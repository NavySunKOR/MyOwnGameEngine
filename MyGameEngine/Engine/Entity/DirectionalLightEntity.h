#pragma once

#include "LightEntity.h"

class MDirectionalLightEntity : MLightEntity
{
public:
	virtual FLocalLightData GetLocalLightData() const;


};