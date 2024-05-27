#pragma once
#include <string>
#include "../Defines/TotalIncludes.h"
/*
	filePath�� ���Ϸ� �ε��ϴ� ��� �����
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