#pragma once
#include "Texture2D.h"

struct FDepthStencilTextureDesc
{

};

class MDepthStencilTexture : public MTexture2D
{
public:
	MDepthStencilTexture(const wchar_t* filePath);
	MDepthStencilTexture(const FDepthStencilTextureDesc texture2DDesc);

protected:
	ComPtr<ID3D11DepthStencilView> m_DSV = nullptr;

};