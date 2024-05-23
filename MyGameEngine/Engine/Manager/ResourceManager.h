#pragma once

class MResourceManager
{
public:
	MResourceManager()
	{
		MResourceManager::instance = this;
	}

	~MResourceManager()
	{
		MResourceManager::instance = nullptr;
	}

	static MResourceManager* instance;

};