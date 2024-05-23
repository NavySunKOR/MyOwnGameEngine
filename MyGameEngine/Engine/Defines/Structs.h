#pragma once


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
