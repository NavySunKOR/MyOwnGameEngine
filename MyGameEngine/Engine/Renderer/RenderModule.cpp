#include "RenderModule.h"
#include "SwapChain.h"
#include "../Resource/Texture/RenderTargetTexture.h"
#include "../Resource/Texture/DepthStencilTexture.h"


using namespace std;

MRenderModule::MRenderModule()
{

}

void MRenderModule::init()
{
    if (!InitDeviceAndContext())
        return;

    if (!InitSwapChain())
        return;

    if (!InitRenderTargetView())
        return;

    if (!InitDepthBuffer())
        return;

    if (!InitDepthStencil())
        return;

    SetViewport();

    m_IsInitialized = true;
}

void MRenderModule::render()
{

}

bool MRenderModule::InitDeviceAndContext()
{
    m_DriverType = D3D_DRIVER_TYPE_HARDWARE;

    // m_device와 m_context 생성

    m_CreateDeviceFlags = 0;
#if defined(DEBUG) || defined(_DEBUG)
    m_CreateDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    ComPtr<ID3D11Device> device;
    ComPtr<ID3D11DeviceContext> context;

    if (FAILED(D3D11CreateDevice(
        nullptr,    // Specify nullptr to use the default adapter.
        m_DriverType, // Create a device using the hardware graphics driver.
        0, // Should be 0 unless the driver is D3D_DRIVER_TYPE_SOFTWARE.
        m_CreateDeviceFlags, // Set debug and Direct2D compatibility flags.
        m_FeatureLevels,     // List of feature levels this app can support.
        ARRAYSIZE(m_FeatureLevels), // Size of the list above.
        D3D11_SDK_VERSION,     // Always set this to D3D11_SDK_VERSION for
        // Microsoft Store apps.
        device.GetAddressOf(), // Returns the Direct3D device created.
        &m_UsingFeatureLevel,         // Returns feature level of device created.
        context.GetAddressOf() // Returns the device immediate context.
    ))) {
        cout << "D3D11CreateDevice() failed." << endl;
        return false;
    }

    if (m_UsingFeatureLevel != D3D_FEATURE_LEVEL_11_0) {
        cout << "D3D Feature Level 11 unsupported." << endl;
        return false;
    }

    // 참고: Immediate vs deferred context
    // A deferred context is primarily used for multithreading and is not
    // necessary for a single-threaded application.
    // https://learn.microsoft.com/en-us/windows/win32/direct3d11/overviews-direct3d-11-devices-intro#deferred-context

    // 4X MSAA 지원하는지 확인
    UINT numQualityLevels; // Resize 처리를 위해 멤버 변수로 변경
    device->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 4,
        &numQualityLevels);
    if (numQualityLevels <= 0) {
        cout << "MSAA not supported." << endl;
        m_MSAAQuality = 0;
    }
    else
    {
        m_MSAAQuality = numQualityLevels;
    }

    if (FAILED(device.As(&m_device))) {
        cout << "device.AS() failed." << endl;
        return false;
    }

    if (FAILED(context.As(&m_context))) {
        cout << "context.As() failed." << endl;
        return false;
    }

    return true;
}

bool MRenderModule::InitSwapChain()
{
    FSwapChainDesc desc;
    desc.m_rectSize;
    //desc.m_windowHandle = parent; 
    m_swapChain = make_shared<MSwapChain>();
	return false;
}

bool MRenderModule::InitRenderTargetView()
{
    if (m_renderTargetView->getRTV())
        m_renderTargetView->getRTV().Reset();

    ComPtr<ID3D11Texture2D> backBuffer;
    m_swapChain->getSwapChain()->GetBuffer(0, IID_PPV_ARGS(backBuffer.GetAddressOf()));
    if (backBuffer) {
        m_renderTargetView = make_shared<MRenderTargetTexture>(backBuffer.Get());
    }
    else {
        std::cout << "CreateRenderTargetView() failed." << std::endl;
        return false;
    }

    return true;
}

bool MRenderModule::InitDepthBuffer()
{
    FTexture2DDesc texture2DDesc;

    texture2DDesc.m_width = m_screenViewport.Width;
    texture2DDesc.m_height = m_screenViewport.Height;
    texture2DDesc.m_mipLevels = 1;
    texture2DDesc.m_format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    if (m_MSAAQuality > 0) {
        texture2DDesc.m_sampleCount = 4; // how many multisamples
        texture2DDesc.m_sampleQuality = m_MSAAQuality - 1;
    }
    else {
        texture2DDesc.m_sampleCount = 1; // how many multisamples
        texture2DDesc.m_sampleQuality = 0;
    }
    texture2DDesc.m_usage = D3D11_USAGE_DEFAULT;
    texture2DDesc.m_bindFlags = D3D11_BIND_DEPTH_STENCIL;
    texture2DDesc.m_CPUAccessFlags = 0;
    texture2DDesc.m_miscFlags = 0;
    m_depthStencilView = make_shared<MDepthStencilTexture>(texture2DDesc);


	return false;
}

bool MRenderModule::InitDepthStencil()
{
	return false;
}

void MRenderModule::SetViewport()
{
    //if (m_swapChain)
    //{
    //    m_swapChain->ResizeBuffers(0, m_AppContext->GetScreenWidth(), m_AppContext->GetScreenHeight(), DXGI_FORMAT_UNKNOWN, 0);
    //    InitRenderTargetView();
    //    InitDepthBuffer();
    //    InitDepthStencil();
    //    SetViewport();
    //}
}
