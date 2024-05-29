#pragma once
#include "Texture.h"

#include <wrl.h>
#include <d3d11.h>


class MTexture2D : public MTexture
{
public:
	MTexture2D() {}
	MTexture2D(const wchar_t* filePath);
	MTexture2D(const FTexture2DDesc texture2DDesc);

	FORCEINLINE Microsoft::WRL::ComPtr<ID3D11Texture2D> getTexture2D() { return m_texture2D; };


protected:
	D3D11_TEXTURE2D_DESC m_texture2DDesc;
	Microsoft::WRL::ComPtr<ID3D11Texture2D> m_texture2D = nullptr;
};