#include "Resource.h"

MResource::MResource(const wchar_t* filePath)
{

}

MResource::~MResource()
{
}

std::wstring MResource::getFilePath()
{
	return m_FilePath;
}
