#include "ResourceManager.h"



//���ҽ� ���常 �صд�.
void MResourceManager::AddResource(const wchar_t* path, MResourcePtr resource)
{
	m_loadedResources.emplace(path, resource);
}