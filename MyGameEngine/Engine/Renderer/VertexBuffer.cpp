#include "VertexBuffer.h"

MVertexBuffer::MVertexBuffer(const FVertexBufferDesc& desc)
{
	D3D11_BUFFER_DESC buffDesc = {};
	buffDesc.Usage = D3D11_USAGE_DEFAULT;
	buffDesc.ByteWidth = desc.vertexSize * desc.listSize;
	buffDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	buffDesc.CPUAccessFlags = 0;
	buffDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = desc.verticesList;

	m_desc = desc;

	/*if (FAILED(m_system->m_d3dDevice->CreateBuffer(&buffDesc, &initData, &m_buffer)))
	{
		throw std::runtime_error("CXVertexBuffer not created successfully");
	}*/

	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		//SEMANTIC NAME - SEMANTIC INDEX - FORMAT - INPUT SLOT - ALIGNED BYTE OFFSET - INPUT SLOT CLASS - INSTANCE CXATA STEP RATE
		{"POSITION", 0,  DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,D3D11_INPUT_PER_VERTEX_DATA ,0},
		{"TEXCOORD", 0,  DXGI_FORMAT_R32G32_FLOAT, 0, 12,D3D11_INPUT_PER_VERTEX_DATA ,0 },
		{"NORMAL", 0,  DXGI_FORMAT_R32G32B32_FLOAT, 0, 20,D3D11_INPUT_PER_VERTEX_DATA ,0 },
		{"TANGENT", 0,  DXGI_FORMAT_R32G32B32_FLOAT, 0, 32,D3D11_INPUT_PER_VERTEX_DATA ,0 },
		{"BINORMAL", 0,  DXGI_FORMAT_R32G32B32_FLOAT, 0, 44,D3D11_INPUT_PER_VERTEX_DATA ,0 },
	};

	UINT size_layout = ARRAYSIZE(layout);

	//if (FAILED(m_system->m_d3dDevice->CreateInputLayout(layout, size_layout, m_system->m_meshLayoutByteCode, m_system->m_meshLayoutSize, &m_layout)))
	//{
	//	throw std::runtime_error("InputLayout not created successfully");
	//}
}

UINT MVertexBuffer::getVerticesListSize() const
{
    return m_desc.listSize;
}

UINT MVertexBuffer::getVertexSize() const
{
    return m_desc.vertexSize;
}

void* MVertexBuffer::getBuffer()
{
    return m_buffer.Get();
}

void* MVertexBuffer::getInputLayout()
{
    return m_layout.Get();
}
