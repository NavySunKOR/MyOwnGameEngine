#include "PointLightEntity.h"

FLocalLightData MPointLightEntity::getLocalLightData() const
{
    FLocalLightData data = MLightEntity::getLocalLightData();
    data.m_radius = m_radius;
    return data;
}
