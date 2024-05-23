#pragma once

#include "../Defines/Enums.h"
#include "../Defines/Structs.h"
#include <d3d11.h>
#include <wrl.h>

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