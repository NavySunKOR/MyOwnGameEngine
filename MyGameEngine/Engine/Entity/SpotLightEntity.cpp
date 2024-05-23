#include "SpotLightEntity.h"

FLocalLightData MSpotLightEntity::GetLocalLightData() const
{
    FLocalLightData Data = MLightEntity::GetLocalLightData();
    Data.m_falloffStart = m_falloffStart;
    Data.m_falloffEnd = m_falloffEnd;
    
    return Data;
}
