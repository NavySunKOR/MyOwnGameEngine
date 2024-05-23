#pragma once
#include "LightEntity.h"


class MPointLightEntity : MLightEntity
{
public:
	virtual FLocalLightData GetLocalLightData() const;

public
	__forceinline void SetRadius(float radius) { m_radius = radius; };
	__forceinline float GetRadius() const { return m_radius; };

private:
	float m_radius = 1.f;
};