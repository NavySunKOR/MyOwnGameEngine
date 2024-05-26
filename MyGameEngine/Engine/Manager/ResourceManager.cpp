#include "ResourceManager.h"



//리소스 저장만 해둔다.
void MResourceManager::AddResource(const wchar_t* path, MResourcePtr resource)
{
	m_loadedResources.emplace(path, resource);
}