#pragma once
#include "Texture.h"


class MTextureCube : public MTexture
{
public:
	MTextureCube(const wchar_t* filePath);
	//TODO: ���߿� uint8* �� �̿��� ���̳��� DDS ���� ���� �����

protected:
	MTextureCube();

protected:
	ComPtr<ID3D11Resource> m_resource;

};