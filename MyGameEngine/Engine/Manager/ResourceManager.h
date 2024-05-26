#pragma once
#include "../Defines/TotalIncludes.h"


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

	void AddResource(const wchar_t* path, MResourcePtr resource);
private:
	std::map<std::wstring, MResourcePtr> m_loadedResources;

};