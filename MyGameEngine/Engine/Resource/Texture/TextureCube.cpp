#include "TextureCube.h"

MTextureCube::MTextureCube(const wchar_t* filePath) : MTexture(filePath)
{

	//TODO: ���� ��⿡�� D3D11 Context�޾ƿͼ� ù��° �Ķ���ͷ� �־��ٰ�.
	//auto hr = DirectX::CreateDDSTextureFromFileEx(
	//	 nullptr, m_FilePath, 0, D3D11_USAGE_DEFAULT,
	//	D3D11_BIND_SHADER_RESOURCE, 0,
	//	D3D11_RESOURCE_MISC_TEXTURECUBE, // ť��ʿ� �ؽ���
	//	DirectX::DDS_LOADER_FLAGS(false), (ID3D11Resource**)m_resource.GetAddressOf(),
	//	m_shaderResView.GetAddressOf(), nullptr);

	//if (FAILED(hr))
	//{
	//	//
	//}
}
