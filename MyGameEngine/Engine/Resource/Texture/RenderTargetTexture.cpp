#include "RenderTargetTexture.h"

MRenderTargetTexture::MRenderTargetTexture(const wchar_t* filePath) : MTexture2D(filePath)
{
	//TODO : ���߿� �𸮾��̳� ��Ÿ ��뿣���� ���� ����Ÿ�� ���¸� �����ؼ� ����Ѵٸ� �ʿ�.
}

MRenderTargetTexture::MRenderTargetTexture(const Texture2DDesc& texture2DDesc, const RenderTargetViewDesc& renderTargetView) : MTexture2D(texture2DDesc)
{
    D3D11_RENDER_TARGET_VIEW_DESC viewDesc;
    viewDesc.Format = m_texture2DDesc.Format;
    viewDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
    viewDesc.Texture2D.MipSlice = 0;

    //TODO: D3D11Context�޾ƿͼ� ����
    //device->CreateRenderTargetView(m_texture2D.Get(), &viewDesc,
        m_RTV.GetAddressOf());

    //���࿡ ���̴� ���ҽ� �� �ٽ� ������ �ȴٸ� �ٽ� �����Ұ�.
}

MRenderTargetTexture::MRenderTargetTexture(ComPtr<ID3D11Texture2D> backBuffer, const RenderTargetViewDesc& renderTargetView)
{

}
