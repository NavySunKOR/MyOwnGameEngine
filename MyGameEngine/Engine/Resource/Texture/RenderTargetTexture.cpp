#include "RenderTargetTexture.h"

MRenderTargetTexture::MRenderTargetTexture(const wchar_t* filePath) : MTexture2D(filePath)
{
	//TODO : ���߿� �𸮾��̳� ��Ÿ ��뿣���� ���� ����Ÿ�� ���¸� �����ؼ� ����Ѵٸ� �ʿ�.
}

MRenderTargetTexture::MRenderTargetTexture(const FTexture2DDesc& texture2DDesc, const FRenderTargetViewDesc& renderTargetView) : MTexture2D(texture2DDesc)
{
    D3D11_RENDER_TARGET_VIEW_DESC viewDesc;
    viewDesc.Format = m_texture2DDesc.Format;
    viewDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
    viewDesc.Texture2D.MipSlice = 0;

    //TODO: D3D11Context�޾ƿͼ� ����
    //device->CreateRenderTargetView(m_texture2D.Get(), &viewDesc, m_RTV.GetAddressOf());

    //���࿡ ���̴� ���ҽ� �� �ٽ� ������ �ȴٸ� �ٽ� �����Ұ�.
}

MRenderTargetTexture::MRenderTargetTexture(ComPtr<ID3D11Texture2D> backBuffer)
{

    /*
    m_device->CreateRenderTargetView(backBuffer.Get(), nullptr, m_RTV);
    
    
    D3D11_TEXTURE2D_DESC desc;
    backBuffer->GetDesc(&desc);
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    desc.MiscFlags = 0;

    if (FAILED(m_device->CreateTexture2D(&desc, nullptr,  m_texture2D.GetAddressOf())) {
        cout << "Failed()" << endl;
    }

    HRESULT Res = m_device->CreateShaderResourceView(m_texture2D.Get(), nullptr, m_renderTargetResourceView.GetAddressOf());
    if (FAILED(Res))
    {
        cout << "Failed CreateShaderResourceView()" << endl;
    }
    */
}


\