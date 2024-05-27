#pragma once
#include <string>
#include "../Defines/TotalIncludes.h"
/*
	filePath는 파일로 로드하는 경우 사용함
*/

class MResource
{
public:
	MResource(const wchar_t* filePath);
	virtual ~MResource();
	FORCEINLINE std::wstring getFilePath() const {
		return m_FilePath;
	};

protected:
	MResource() {}

protected:
	std::wstring m_FilePath;
	
};