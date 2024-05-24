#pragma once
#include "Texture2D.h"

class MRenderTargetTexture : public MTexture2D
{
public:
	MRenderTargetTexture(const wchar_t* filePath);
	MRenderTargetTexture(const FTexture2DDesc& texture2DDesc , const FRenderTargetViewDesc& renderTargetView);
	MRenderTargetTexture(ComPtr<ID3D11Texture2D> backBuffer, const FRenderTargetViewDesc& renderTargetView);

protected:
	ComPtr<ID3D11RenderTargetView> m_RTV = nullptr;

};