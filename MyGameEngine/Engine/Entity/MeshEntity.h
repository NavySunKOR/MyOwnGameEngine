#pragma once
#include "Entity.h"
#include "../Defines/TotalIncludes.h"

class MMesh;

class MMeshEntity : public MEntity 
{
public :
	MMeshEntity();
	virtual ~MMeshEntity();

public:
	FORCEINLINE void setMesh(const MMeshPtr& pMesh) { m_mesh = pMesh; };

	MMeshPtr m_mesh;

};