#include "LightEntity.h"

FLocalLightData MLightEntity::GetLocalLightData() const
{
    FLocalLightData Data;
    Data.m_intensity = m_intensity;
    return Data;
}
