#include "LightEntity.h"

FLocalLightData MLightEntity::getLocalLightData() const
{
    FLocalLightData Data;
    Data.m_intensity = m_intensity;
    Data.m_LightColor = m_color;
    return Data;
}
