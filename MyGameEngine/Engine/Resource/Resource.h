#pragma once
#include <string>

class MResource
{
	//���Ϸ� �ε��ϴ� ��� �߰� �ʿ�.
public:
	MResource(const wchar_t* filePath);
	virtual ~MResource();
	std::wstring getFilePath();

protected:
	std::wstring m_FilePath;
	
};