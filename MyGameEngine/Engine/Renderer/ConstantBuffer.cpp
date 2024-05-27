#include "ConstantBuffer.h"

MConstantBuffer::MConstantBuffer(const FConstantBufferDesc& desc)
{
	D3D11_BUFFER_DESC buffDesc = {};
	buffDesc.Usage = D3D11_USAGE_DEFAULT;
	buffDesc.ByteWidth = desc.bufferSize;
	buffDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	buffDesc.CPUAccessFlags = 0;
	buffDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = desc.buffer;
	//auto device = m_system->m_d3dDevice;

	//if (FAILED(device->CreateBuffer(&buffDesc, &initData, &m_buffer)))
	//	throw std::runtime_error("CXConstantBuffer not created successfully");
}

void MConstantBuffer::update(void* buffer)
{
	//m_system->m_immContext->UpdateSubresource(this->m_buffer.Get(), NULL, NULL, buffer, NULL, NULL);
}

void* MConstantBuffer::getBuffer()
{
	return m_buffer.Get();
}
