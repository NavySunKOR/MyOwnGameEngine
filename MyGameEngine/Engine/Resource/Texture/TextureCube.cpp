#include "TextureCube.h"

MTextureCube::MTextureCube(const wchar_t* filePath) : MTexture(filePath)
{

	//TODO: 렌더 모듈에서 D3D11 Context받아와서 첫번째 파라미터로 넣어줄것.
	//auto hr = DirectX::CreateDDSTextureFromFileEx(
	//	 nullptr, m_FilePath, 0, D3D11_USAGE_DEFAULT,
	//	D3D11_BIND_SHADER_RESOURCE, 0,
	//	D3D11_RESOURCE_MISC_TEXTURECUBE, // 큐브맵용 텍스춰
	//	DirectX::DDS_LOADER_FLAGS(false), (ID3D11Resource**)m_resource.GetAddressOf(),
	//	m_shaderResView.GetAddressOf(), nullptr);

	//if (FAILED(hr))
	//{
	//	//
	//}
}
