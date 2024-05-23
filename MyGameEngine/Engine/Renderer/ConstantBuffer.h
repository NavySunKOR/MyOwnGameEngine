#pragma once
#include "../Defines/Enums.h"
#include "../Defines/Structs.h"
#include <d3d11.h>
#include <wrl.h>

class  MConstantBuffer
{
public:
	MConstantBuffer(const FConstantBufferDesc& desc);
	void update(void* buffer);
	void* getBuffer();
private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_buffer;
};