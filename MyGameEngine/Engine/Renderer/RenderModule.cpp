#include "RenderModule.h"

using namespace std;

MRenderModule::MRenderModule()
{

}

void MRenderModule::init()
{

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

bool MRenderModule::InitRasterizerState()
{
	return false;
}

bool MRenderModule::InitRenderTargetView()
{
	return false;
}

bool MRenderModule::InitDepthBuffer()
{
	return false;
}

bool MRenderModule::InitDepthStencil()
{
	return false;
}

bool MRenderModule::InitSampler()
{
	return false;
}

void MRenderModule::SetViewport()
{

}
