#include "DepthStencilTexture.h"

MDepthStencilTexture::MDepthStencilTexture(const wchar_t* filePath)
{
	//TODO : ���࿡ �������� �����ؼ� ���ٸ� ���� ���� ���� �߰� �� ��.
}

MDepthStencilTexture::MDepthStencilTexture(const FTexture2DDesc& texture2DDesc) : MTexture2D(texture2DDesc)
{
	//TODO: ���� ��⿡�� Direct X ��  DeviceContext �����ð�
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
