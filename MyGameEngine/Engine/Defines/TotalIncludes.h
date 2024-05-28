#pragma once
#include <d3d11.h>
#include <wrl.h>
#include <d3dcompiler.h>
#include <directxtk/SimpleMath.h>
#include <directxtk/DDSTextureLoader.h> 
#include <directxtk/WICTextureLoader.h>
#include <memory>
#include <sstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <stdexcept>

//멀티플랫폼 사용을 위해서는 방식을 변경하여야하지만 지금은 Direct X 하나만 다룬다는 전제 조건으로 간다. 멀티플랫폼이 어쩌구 저쩌구 하면 돌아가는 엔진조차 못만듬.
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace Microsoft::WRL;

#define FORCEINLINE __forceinline

typedef std::shared_ptr<class MMesh> MMeshPtr;
typedef std::shared_ptr<class MTexture2D> MTexture2DPtr;
typedef std::shared_ptr<class MTextureCube> MTextureCubePtr;
typedef std::shared_ptr<class MRenderTargetTexture> MRenderTargetTexturePtr;
typedef std::shared_ptr<class MDepthStencilTexture> MDepthStencilTexturePtr;
typedef std::shared_ptr<class MMaterial> MMaterialPtr;
typedef std::shared_ptr<class MVertexBuffer> MVertexBufferPtr;
typedef std::shared_ptr<class MIndexBuffer> MIndexBufferPtr;
typedef std::shared_ptr<class MConstantBuffer> MConstantBufferPtr;
typedef std::shared_ptr<class MResource> MResourcePtr;
typedef std::shared_ptr<class MSwapChain> MSwapChainPtr;



enum class EProjectionMode
{
	PERSPECTIVE = 0,
	ORTHOGRAPHIC
};

enum class ELightType
{
	DIRECTIONAL,
	POINT,
	SPOT,
	RECT
};

enum class EVolumetricLightType
{
	SPHERE,
	CUBE
};

enum class  EKey
{
	Escape = 0,
	Shift,
	Space,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	N0,
	N1,
	N2,
	N3,
	N4,
	N5,
	N6,
	N7,
	N8,
	N9,
	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	F10,
	F11,
	F12,
};

enum class EMouseButton
{
	Left = 0,
	Middle,
	Right
};

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
public:
	void* verticesList = nullptr;
	UINT vertexSize = 0;
	UINT listSize = 0;
};

struct FIndexBufferDesc
{
public:
	void* indicesList = nullptr;
	UINT listSize = 0;
};

struct FConstantBufferDesc
{
	void* buffer = nullptr;
	UINT bufferSize = 0;
};


struct FTexture2DDesc
{
public:
	UINT m_width = 0;
	UINT m_height = 0;
	UINT m_mipLevels = 0;
	DXGI_FORMAT m_format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	UINT m_sampleCount = 1;
	D3D11_USAGE m_usage = D3D11_USAGE_DEFAULT;
	UINT m_bindFlags = D3D11_BIND_SHADER_RESOURCE;
	UINT m_miscFlags = 0;
	UINT m_CPUAccessFlags = 0;
};



struct FTextureCubeDesc
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

struct FSwapChainDesc
{
public:
	void* m_windowHandle = nullptr;
	UINT m_MSAAApplyLevel = 0;
	DirectX::SimpleMath::Rectangle m_rectSize;
};

struct FRenderTargetViewDesc
{
public:
	DXGI_FORMAT m_format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	D3D11_RTV_DIMENSION m_RTVDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	UINT m_mipSlice = 0;
};

struct FVertex
{
	Vector3 m_position;
	Vector3 m_normal;
	Vector2 m_texCoord;
};

struct FMaterialSlot
{
	size_t startIndex = 0;
	size_t numIndices = 0;
	size_t materialID = 0;
};