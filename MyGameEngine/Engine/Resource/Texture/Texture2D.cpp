#include "Texture2D.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include <vector>
#include <comdef.h>

MTexture2D::MTexture2D(const wchar_t* filePath) : MTexture(filePath)
{
	int width, height, channels;

	_bstr_t toChar(filePath);

	unsigned char* img = stbi_load(toChar, &width, &height, &channels, 0);

	if (img == nullptr)
	{
		std::cout << "Image Doesn't exist!" << std::endl;
		return;
	}

	std::vector<uint8_t> colors;

	colors.resize(size_t(width * height * channels));

	memcpy(colors.data(), img, colors.size() * sizeof(uint8_t));


	//추가 설정이 필요할지 아닐지는 나중에 보고 판단한다.
	D3D11_TEXTURE2D_DESC txtDesc = {};
	txtDesc.Width = width;
	txtDesc.Height = height;
	txtDesc.MipLevels = txtDesc.ArraySize = 1;
	txtDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; 
	txtDesc.SampleDesc.Count = 1;
	txtDesc.Usage = D3D11_USAGE_IMMUTABLE;
	txtDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;

	// Fill in the subresource data.
	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = colors.data();
	InitData.SysMemPitch = txtDesc.Width * sizeof(uint8_t) * channels;

	m_texture2DDesc = txtDesc;

	//TODO: D3D11Context받아와서 실행
	//pDeviceContext->CreateTexture2D(&txtDesc, &InitData, m_texture2D.GetAddressOf());
	//pDeviceContext->CreateShaderResourceView(m_texture2D.Get(), nullptr, m_shaderResView.GetAddressOf());


}

MTexture2D::MTexture2D(const Texture2DDesc texture2DDesc) : MTexture(nullptr) // 동적 생성은 파일 명칭이 필요 없다. 추 후에 저장 로직에서나 추가하도록 하자.
{
    D3D11_TEXTURE2D_DESC txtDesc;
    ZeroMemory(&txtDesc, sizeof(txtDesc));
    txtDesc.Width = texture2DDesc.m_width;
    txtDesc.Height = texture2DDesc.m_height;
    txtDesc.MipLevels = txtDesc.ArraySize = texture2DDesc.m_mipLevels;
    txtDesc.Format = texture2DDesc.m_format; //  이미지 처리용도
    txtDesc.SampleDesc.Count = texture2DDesc.m_sampleCount;
    txtDesc.Usage = texture2DDesc.m_usage;
    txtDesc.BindFlags = texture2DDesc.m_bindFlags;
    txtDesc.MiscFlags = texture2DDesc.m_miscFlags;
    txtDesc.CPUAccessFlags = texture2DDesc.m_CPUAccessFlags;

    D3D11_SUBRESOURCE_DATA InitData;
    InitData.pSysMem = nullptr;
    InitData.SysMemPitch = txtDesc.Width * sizeof(uint8_t) * 1; // 채널 한개라고 가정

	m_texture2DDesc = txtDesc;

    //TODO: D3D11Context받아와서 실행
    //pDeviceContext->CreateTexture2D(&txtDesc, &InitData, m_texture2D.GetAddressOf());
    //pDeviceContext->CreateShaderResourceView(m_texture2D.Get(), nullptr, m_shaderResView.GetAddressOf());
}
