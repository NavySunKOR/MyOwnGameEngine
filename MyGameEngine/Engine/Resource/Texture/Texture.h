#pragma once
#include "../Resource.h"

using namespace Microsoft::WRL;

class MTexture : public MResource
{
public:
	MTexture(const wchar_t* filePath);

	FORCEINLINE void ChangeSamplerState(ComPtr<ID3D11SamplerState> inSamplerState) {
		m_samplerState = inSamplerState;
	};

protected:
	MTexture() {}

protected:
	ComPtr<ID3D11ShaderResourceView> m_shaderResView = nullptr;
	ComPtr<ID3D11SamplerState> m_samplerState = nullptr;

};