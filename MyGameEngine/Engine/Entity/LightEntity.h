#pragma once
#include "Entity.h"

class MLightEntity : MEntity
{
public:
	FORCEINLINE void setColor(const  Vector3& color) { m_color = color; };
	FORCEINLINE Vector3 getColor() { return m_color; };

	FORCEINLINE float getIntensity() const { return m_intensity; }
	FORCEINLINE void setIntensity(float pIntensity) { m_intensity = pIntensity; }
	
	virtual FLocalLightData getLocalLightData() const;
	
private:
	Vector3 m_color = Vector3(1, 1, 1);
	float m_intensity = 1.f;
	
};