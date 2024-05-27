#pragma once
#include "LightEntity.h"


class MSpotLightEntity : MLightEntity
{
public:
	virtual FLocalLightData getLocalLightData() const override;

public:
	FORCEINLINE void SetFalloffStart(float falloffStart) { m_falloffStart = falloffStart; };
	FORCEINLINE void SetFalloffEnd(float falloffEnd) { m_falloffEnd = falloffEnd; };
	FORCEINLINE float GetFalloffStart() const { return m_falloffStart; };
	FORCEINLINE float GetFalloffEnd() const { return m_falloffEnd; };

private:
	float m_falloffStart = 1.f;
	float m_falloffEnd = 5.f;
};