#include "DepthStencilTexture.h"

MDepthStencilTexture::MDepthStencilTexture(const wchar_t* filePath)
{
	//TODO : 만약에 에셋으로 저장해서 쓴다면 에셋 관련 로직 추가 할 것.
}

MDepthStencilTexture::MDepthStencilTexture(const FTexture2DDesc& texture2DDesc) : MTexture2D(texture2DDesc)
{
	//TODO: 렌더 모듈에서 Direct X 의  DeviceContext 가져올것
	//m_device->CreateDepthStencilView(m_texture2D.Get(), 0, &m_DSV));

  /*  if (FAILED(m_device->CreateTexture2D(&depthStencilBufferDesc, 0, m_depthStencilBuffer.GetAddressOf()))) {
        std::cout << "CreateTexture2D() failed." << std::endl;
        return false;
    }
    if (FAILED(m_device->CreateDepthStencilView(m_depthStencilBuffer.Get(), 0, &m_depthStencilView))) {
        std::cout << "CreateDepthStencilView() failed." << std::endl;
        return false;
    }*/
}
