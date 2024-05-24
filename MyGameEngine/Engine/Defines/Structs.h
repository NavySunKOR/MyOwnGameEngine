#pragma once
#include "EssentialGraphicIncludes.h"
/*
	로컬 라이트. 특정 볼륨을 가진 영역이 아닌 라이트의 데이터(예 : DirectionalLight , Point, SpotLight 같은것) 
	언리얼에서 두개를 구분하길래 일단 구분해놓았다.
*/
struct FLocalLightData
{
public:
	Vector3 m_LightColor;
	Vector3 m_position;
	Vector3 m_rotation;
	float m_radius;
	float m_falloffStart;
	float m_falloffEnd;
	float m_intensity;

	Matrix m_viewProjection;
	Matrix m_invProjection;

	FLocalLightData()
	{
		this->m_radius = 0.f;
		this->m_falloffStart = 0.f;
		this->m_falloffEnd = 0.f;
		this->m_intensity = 1.f;
	}
};

/*
	지역 라이트. 특정 볼륨을 가진 영역인 라이트의 데이터(예 : Rect Light)
	언리얼에서 두개를 구분하길래 일단 구분해놓았다.
*/
struct FAreaLightData
{

};


struct FVertexBufferDesc
{

};

struct FIndexBufferDesc
{

};

struct FConstantBufferDesc
{

};


struct Texture2DDesc
{
public:
	UINT m_width = 0;
	UINT m_height = 0;
	UINT m_mipLevels = 0;
	DXGI_FORMAT m_format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	UINT m_sampleCount = 1 ;
	D3D11_USAGE m_usage = D3D11_USAGE_DEFAULT;
	UINT m_bindFlags = D3D11_BIND_SHADER_RESOURCE;
	UINT m_miscFlags = 0;
	UINT m_CPUAccessFlags = 0;
};



struct TextureCubeDesc
{
public:
	UINT m_maxSize = 0;
	D3D11_USAGE m_usage = D3D11_USAGE_DEFAULT;
	UINT m_bindFlag = D3D11_BIND_SHADER_RESOURCE;
	UINT m_miscFlags = 0;
	UINT m_CPUAccessFlags = 0;
	DirectX::DX11::DDS_LOADER_FLAGS m_ddsLoadFlags = DirectX::DX11::DDS_LOADER_FLAGS(false);
	ID3D11Resource** m_textureResourcePtr = nullptr;
	ID3D11Resource** m_shaderResourceViewPtr = nullptr;

	DirectX::DDS_ALPHA_MODE* m_ddsAlphaMode = nullptr;

};

struct RenderTargetViewDesc
{
public:
	DXGI_FORMAT m_format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	D3D11_RTV_DIMENSION m_RTVDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	UINT m_mipSlice = 0;
};
