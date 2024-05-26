#pragma once
#include "Entity.h"

class MLightEntity : MEntity
{
public:
	__forceinline void setColor(const  Vector3& color) { m_color = color; };
	__forceinline Vector3 getColor() { return m_color; };

	__forceinline float getIntensity() const { return m_intensity; }
	__forceinline void setIntensity(float pIntensity) { m_intensity = pIntensity; }
	
	virtual FLocalLightData getLocalLightData() const;
	
private:
	Vector3 m_color = Vector3(1, 1, 1);
	float m_intensity = 1.f;
	
};