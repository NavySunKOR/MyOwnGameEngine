#include "IndexBuffer.h"

MIndexBuffer::MIndexBuffer(const FIndexBufferDesc& desc)
{
	D3D11_BUFFER_DESC buffDesc = {};
	buffDesc.Usage = D3D11_USAGE_DEFAULT;
	buffDesc.ByteWidth = 4 * desc.listSize;
	buffDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	buffDesc.CPUAccessFlags = 0;
	buffDesc.MiscFlags = 0;


	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = desc.indicesList;

	m_desc = desc;


	//TODO: Device 가져오기
	/*if (FAILED(m_system->m_d3dDevice->CreateBuffer(&buffDesc, &initData, &m_buffer)))
		throw std::runtime_error("MIndexBuffer not created successfully");*/
}

int MIndexBuffer::getIndicesListSize()
{
	return m_desc.listSize;
}

void* MIndexBuffer::getBuffer()
{
	return m_buffer.Get();
}
