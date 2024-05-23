#pragma once
#include "Texture.h"

struct Texture2DDesc
{

};

class MTexture2D : public MTexture
{
public:
	MTexture2D(const wchar_t* filePath);
	MTexture2D(const Texture2DDesc texture2DDesc);

protected:
	Microsoft::WRL::ComPtr<ID3D11Texture2D> m_texture = nullptr;
};