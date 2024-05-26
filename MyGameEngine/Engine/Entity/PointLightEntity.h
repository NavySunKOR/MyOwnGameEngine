#pragma once
#include "LightEntity.h"


class MPointLightEntity : MLightEntity
{
public:
	virtual FLocalLightData getLocalLightData() const override;

public:
	FORCEINLINE void SetRadius(float radius) { m_radius = radius; };
	FORCEINLINE float GetRadius() const { return m_radius; };

protected:
	float m_radius = 1.f;
};