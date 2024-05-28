#pragma once

#include "../Defines/TotalIncludes.h"

class MRenderModule
{

public:
	MRenderModule();

public:
	virtual void init();
	virtual void render();

	FORCEINLINE ComPtr<ID3D11Device>& GetDevice() {
		return m_device;
	};

	FORCEINLINE ComPtr<ID3D11DeviceContext>& GetContext() {
		return m_context;
	};

	FORCEINLINE MSwapChainPtr GetSwapChain() {
		return m_swapChain;
	};

	FORCEINLINE MRenderTargetTexturePtr GetRenderTargetView() {
		return m_renderTargetView;
	};

	FORCEINLINE D3D11_VIEWPORT& GetScreenViewport() {
		return m_screenViewport;
	};

private:
	bool InitDeviceAndContext();
	bool InitSwapChain();
	bool InitRasterizerState();
	bool InitRenderTargetView();
	bool InitDepthBuffer();
	bool InitDepthStencil();
	bool InitSampler();
	void SetViewport();

protected:
	class MCameraEntity* m_mainCamera;
	ComPtr<ID3D11Device> m_device; //����̽�
	ComPtr<ID3D11DeviceContext> m_context; //���ؽ�Ʈ 
	D3D11_VIEWPORT m_screenViewport;

	MSwapChainPtr m_swapChain;
	MRenderTargetTexturePtr m_renderTargetView;
	MDepthStencilTexturePtr m_depthStencilView;
	ComPtr<ID3D11DepthStencilState> m_depthStencilState; //���� ���ٽ� ������Ʈ

	//TODO: ������Ʈ�� ��� �� �� ��� �ʿ�

#pragma region DirectXProperties
private:
	UINT m_MSAAQuality;
	D3D_DRIVER_TYPE m_DriverType;
	UINT m_CreateDeviceFlags;

	D3D_FEATURE_LEVEL m_FeatureLevels[2] = {
		D3D_FEATURE_LEVEL_11_0, // �� ���� ������ ���� ������ ����
		D3D_FEATURE_LEVEL_9_3 };

	D3D_FEATURE_LEVEL m_UsingFeatureLevel;


#pragma endregion

private:
	friend class  MSwapChain;
	friend class  MVertexBuffer;
	friend class  MIndexBuffer;
	friend class  MConstantBuffer;
	friend class  MTexture2D;
	friend class MCameraEntity;
}