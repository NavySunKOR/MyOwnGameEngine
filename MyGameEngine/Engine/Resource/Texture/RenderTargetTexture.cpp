#include "RenderTargetTexture.h"

MRenderTargetTexture::MRenderTargetTexture(const wchar_t* filePath) : MTexture2D(filePath)
{
	//TODO : 나중에 언리얼이나 기타 상용엔진과 같이 렌더타겟 형태를 저장해서 사용한다면 필요.
}

MRenderTargetTexture::MRenderTargetTexture(const Texture2DDesc& texture2DDesc, const RenderTargetViewDesc& renderTargetView) : MTexture2D(texture2DDesc)
{
    D3D11_RENDER_TARGET_VIEW_DESC viewDesc;
    viewDesc.Format = m_texture2DDesc.Format;
    viewDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
    viewDesc.Texture2D.MipSlice = 0;

    //TODO: D3D11Context받아와서 실행
    //device->CreateRenderTargetView(m_texture2D.Get(), &viewDesc,
        m_RTV.GetAddressOf());

    //만약에 쉐이더 리소스 뷰 다시 만들어야 된다면 다시 설정할것.
}

MRenderTargetTexture::MRenderTargetTexture(ComPtr<ID3D11Texture2D> backBuffer, const RenderTargetViewDesc& renderTargetView)
{

}
