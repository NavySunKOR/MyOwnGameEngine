#include "SwapChain.h"
#include "../Resource/Texture/DepthStencilTexture.h"
#include "../Resource/Texture/RenderTargetTexture.h"

MSwapChain::MSwapChain(const FSwapChainDesc& swapDesc)
{
	DXGI_SWAP_CHAIN_DESC d3d11Desc = {};
	d3d11Desc.BufferCount = 1;
	d3d11Desc.BufferDesc.Width = (swapDesc.m_rectSize.width > 0) ? swapDesc.m_rectSize.width : 1;
	d3d11Desc.BufferDesc.Height = (swapDesc.m_rectSize.height > 0) ? swapDesc.m_rectSize.height : 1;
	d3d11Desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	d3d11Desc.BufferDesc.RefreshRate.Numerator = 60;
	d3d11Desc.BufferDesc.RefreshRate.Denominator = 1;
	d3d11Desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	d3d11Desc.OutputWindow = (HWND)swapDesc.windowHandle;
	d3d11Desc.SampleDesc.Count = 1;
	d3d11Desc.SampleDesc.Quality = 0;
	d3d11Desc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	d3d11Desc.Windowed = TRUE;

	/*HRESULT hr = m_system->m_dxgiFactory->CreateSwapChain(device.Get(), &d3d11Desc, &m_swap_chain);

	if (FAILED(hr)) throw std::runtime_error("DSwapChain not created successfully");

	reloadBuffers(desc.size.width, desc.size.height);*/
}

void MSwapChain::setFullScreen(const bool isFullScreen)
{
	m_swapChain->SetFullscreenState(isFullScreen, nullptr);
}

void MSwapChain::resize(const DirectX::SimpleMath::Rectangle& inSize)
{
	m_rtv->GetRTV().Reset();
	m_dsv->GetDSV().Reset();

	m_swapChain->ResizeBuffers(1, size.width, size.height, DXGI_FORMAT_R8G8B8A8_UNORM, 0);
	reloadBuffer(size.width, size.height);
}

bool MSwapChain::present(bool vsync)
{
	m_swapChain->Present(vsync, NULL);
	return vsync;
}

void MSwapChain::reloadBuffer(UINT pWidth, UINT pHeight)
{
	auto device = m_system->m_d3dDevice;

	//Get the back buffer color and create its render target view
	//--------------------------------
	ID3D11Texture2D* buffer = NULL;
	HRESULT hr = m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer);

	if (FAILED(hr))throw std::runtime_error("DSwapChain not created successfully");


	hr = device->CreateRenderTargetView(buffer, NULL, &m_rtv);
	buffer->Release();

	if (FAILED(hr))throw std::runtime_error("DSwapChain not created successfully");


	D3D11_TEXTURE2D_DESC tex_desc = {};
	tex_desc.Width = (pWidth > 0) ? pWidth : 1;
	tex_desc.Height = (pHeight > 0) ? pHeight : 1;
	tex_desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	tex_desc.Usage = D3D11_USAGE_DEFAULT;
	tex_desc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	tex_desc.MipLevels = 1;
	tex_desc.SampleDesc.Count = 1;
	tex_desc.SampleDesc.Quality = 0;
	tex_desc.MiscFlags = 0;
	tex_desc.ArraySize = 1;
	tex_desc.CPUAccessFlags = 0;


	hr = device->CreateTexture2D(&tex_desc, nullptr, &buffer);
	if (FAILED(hr))
		throw std::runtime_error("DSwapChain not created successfully");


	hr = device->CreateDepthStencilView(buffer, NULL, &m_dsv);
	buffer->Release();

	if (FAILED(hr)) throw std::runtime_error("DSwapChain not created successfully");
}
