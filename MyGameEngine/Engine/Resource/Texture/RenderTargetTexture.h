#pragma once
#include "Texture2D.h"

class MRenderTargetTexture : public MTexture2D
{
public:
	MRenderTargetTexture(const wchar_t* filePath);
	MRenderTargetTexture(const Texture2DDesc& texture2DDesc , const RenderTargetViewDesc& renderTargetView);
	MRenderTargetTexture(ComPtr<ID3D11Texture2D> backBuffer, const RenderTargetViewDesc& renderTargetView);

protected:
	ComPtr<ID3D11RenderTargetView> m_RTV = nullptr;

};