#include "SpotLightEntity.h"

FLocalLightData MSpotLightEntity::getLocalLightData() const
{
    FLocalLightData Data = MLightEntity::getLocalLightData();
    Data.m_falloffStart = m_falloffStart;
    Data.m_falloffEnd = m_falloffEnd;
    
    return Data;
}
