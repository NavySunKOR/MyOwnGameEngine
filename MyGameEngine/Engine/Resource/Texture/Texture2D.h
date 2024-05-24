#pragma once
#include "Texture.h"

#include <wrl.h>
#include <d3d11.h>


class MTexture2D : public MTexture
{
public:
	MTexture2D(const wchar_t* filePath);
	MTexture2D(const Texture2DDesc texture2DDesc);

protected:
	MTexture2D() {}

protected:
	D3D11_TEXTURE2D_DESC m_texture2DDesc;
	Microsoft::WRL::ComPtr<ID3D11Texture2D> m_texture2D = nullptr;
};