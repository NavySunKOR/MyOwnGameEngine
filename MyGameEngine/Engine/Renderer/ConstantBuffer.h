#pragma once

#include "../Defines/TotalIncludes.h"

class  MConstantBuffer
{
public:
	MConstantBuffer(const FConstantBufferDesc& desc);
	void update(void* buffer);
	void* getBuffer();
private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_buffer;
};