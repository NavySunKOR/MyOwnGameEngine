#pragma once
#include "../Defines/TotalIncludes.h"


class MSwapChain
{
public:
	MSwapChain(const FSwapChainDesc& swapDesc);
	void setFullScreen(const bool isFullScreen);
	void resize(const DirectX::SimpleMath::Rectangle& inSize);
	bool present(bool vsync);

	FORCEINLINE Microsoft::WRL::ComPtr <IDXGISwapChain> getSwapChain() { return m_swapChain; };
	FORCEINLINE MRenderTargetTexturePtr getRenderTargetView() { return m_rtv; };
	FORCEINLINE MDepthStencilTexturePtr getDepthStencilView() { return m_dsv; };

private: 
	void reloadBuffer(UINT pWidth, UINT pHeight);

	Microsoft::WRL::ComPtr <IDXGISwapChain> m_swapChain = nullptr;
	MRenderTargetTexturePtr m_rtv = nullptr;
	MDepthStencilTexturePtr m_dsv = nullptr;

};