#include "DepthStencilTexture.h"

MDepthStencilTexture::MDepthStencilTexture(const wchar_t* filePath)
{
	//TODO : ���࿡ �������� �����ؼ� ���ٸ� ���� ���� ���� �߰� �� ��.
}

MDepthStencilTexture::MDepthStencilTexture(const FTexture2DDesc& texture2DDesc) : MTexture2D(texture2DDesc)
{
	//TODO: ���� ��⿡�� Direct X ��  DeviceContext �����ð�
	//m_device->CreateDepthStencilView(m_texture2D.Get(), 0, &m_DSV));
}
