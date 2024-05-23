#pragma once
#include "../Resource.h"
#include <d3d11.h>
#include <wrl.h>

using namespace Microsoft::WRL;

class MTexture : public MResource
{
public: 
	MTexture(const wchar_t* filePath);

	__forceinline void ChangeSamplerState(ComPtr<ID3D11SamplerState> inSamplerState) {
		m_samplerState = inSamplerState;
	};
protected:
	ComPtr<ID3D11ShaderResourceView> m_shaderResView = nullptr;
	ComPtr<ID3D11SamplerState> m_samplerState = nullptr;

};