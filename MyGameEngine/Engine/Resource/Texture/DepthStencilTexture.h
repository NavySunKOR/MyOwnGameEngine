#pragma once
#include "Texture2D.h"


class MDepthStencilTexture : public MTexture2D
{
public:
	MDepthStencilTexture(const wchar_t* filePath);
	MDepthStencilTexture(const FTexture2DDesc& texture2DDesc);
	FORCEINLINE ComPtr<ID3D11DepthStencilView> GetDSV() { return m_DSV; };

protected:
	ComPtr<ID3D11DepthStencilView> m_DSV = nullptr;

};