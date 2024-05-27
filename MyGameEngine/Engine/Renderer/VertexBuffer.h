#pragma once

#include "../Defines/TotalIncludes.h"

class MVertexBuffer
{
public:
	MVertexBuffer(const FVertexBufferDesc& desc);
	UINT getVerticesListSize() const;
	UINT getVertexSize() const;
	void* getBuffer();
	void* getInputLayout();

private:
	FVertexBufferDesc m_desc;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_buffer;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_layout;
};