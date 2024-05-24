#pragma once
#include "Texture.h"


class MTextureCube : public MTexture
{
public:
	MTextureCube(const wchar_t* filePath);
	//TODO: 나중에 uint8* 로 이용한 다이나믹 DDS 생성 로직 만들기

protected:
	MTextureCube();

protected:
	ComPtr<ID3D11Resource> m_resource;

};