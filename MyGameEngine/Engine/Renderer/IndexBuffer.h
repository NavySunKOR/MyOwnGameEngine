#pragma once

#include "../Defines/TotalIncludes.h"

class  MIndexBuffer
{
public:
	MIndexBuffer(const FIndexBufferDesc& desc);
	int getIndicesListSize();
	void* getBuffer();
private:
	FIndexBufferDesc m_desc;
private:
	Microsoft::WRL::ComPtr <ID3D11Buffer> m_buffer;
};