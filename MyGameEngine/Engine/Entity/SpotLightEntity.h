#pragma once
#include "LightEntity.h"


class MSpotLightEntity : MLightEntity
{
public:
	virtual FLocalLightData getLocalLightData() const override;

public:
	__forceinline void SetFalloffStart(float falloffStart) { m_falloffStart = falloffStart; };
	__forceinline void SetFalloffEnd(float falloffEnd) { m_falloffEnd = falloffEnd; };
	__forceinline float GetFalloffStart() const { return m_falloffStart; };
	__forceinline float GetFalloffEnd() const { return m_falloffEnd; };

private:
	float m_falloffStart = 1.f;
	float m_falloffEnd = 5.f;
};