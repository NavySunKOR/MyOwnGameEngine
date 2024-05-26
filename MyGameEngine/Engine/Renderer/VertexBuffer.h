#pragma once

#include "../Defines/TotalIncludes.h"

class MVertexBuffer
{
public:
	MVertexBuffer(const FVertexBufferDesc& desc);
	void* getBuffer();
	void* getInputLayout();

private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_buffer;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_layout;
};