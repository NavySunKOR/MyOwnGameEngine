#pragma once
#include <string>

class MResource
{
	//파일로 로드하는 경우 추가 필요.
public:
	MResource(const wchar_t* filePath);
	virtual ~MResource();
	std::wstring getFilePath();

protected:
	std::wstring m_FilePath;
	
};