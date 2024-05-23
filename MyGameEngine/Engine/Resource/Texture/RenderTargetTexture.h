#pragma once
#include "Texture2D.h"

struct RenderTargetTextureDesc
{

};

class MRenderTargetTexture : public MTexture2D
{
public:
	MRenderTargetTexture(const wchar_t* filePath);
	MRenderTargetTexture(const RenderTargetTextureDesc texture2DDesc);

protected:
	ComPtr<ID3D11RenderTargetView> m_RTV = nullptr;

};