#pragma once


/*
	���� ����Ʈ. Ư�� ������ ���� ������ �ƴ� ����Ʈ�� ������(�� : DirectionalLight , Point, SpotLight ������) 
	�𸮾󿡼� �ΰ��� �����ϱ淡 �ϴ� �����س��Ҵ�.
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
	���� ����Ʈ. Ư�� ������ ���� ������ ����Ʈ�� ������(�� : Rect Light)
	�𸮾󿡼� �ΰ��� �����ϱ淡 �ϴ� �����س��Ҵ�.
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
