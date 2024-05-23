#pragma once
#include "LightEntity.h"


class MPointLightEntity : MLightEntity
{
public:
	virtual FLocalLightData getLocalLightData() const override;

public
	__forceinline void SetRadius(float radius) { m_radius = radius; };
	__forceinline float GetRadius() const { return m_radius; };

protected:
	float m_radius = 1.f;
};