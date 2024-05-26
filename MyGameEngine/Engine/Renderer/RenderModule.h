#pragma once

#include "../Defines/TotalIncludes.h"

class MRenderModule
{

public:
	MRenderModule();
public:
	CXSwapChainPtr createSwapChain(const CXSwapChainDesc& desc);
	CXVertexBufferPtr createVertexBuffer(const CXVertexBufferDesc& desc);
	CXIndexBufferPtr createIndexBuffer(const CXIndexBufferDesc& desc);
	CXConstantBufferPtr createConstantBuffer(const CXConstantBufferDesc& desc);
	CXShaderPtr createShader(const CXShaderDesc& desc);
	CXTexture2DPtr createTexture2D(const CXTexture2DDesc& desc);
	CXTexture2DPtr createTexture2D(const wchar_t* path);
public:
	void clearColor(const  CXSwapChainPtr& swap_chain, const CXVec4& color);
	void clearDepthStencil(const  CXSwapChainPtr& swap_chain);

	void clearColor(const  CXTexture2DPtr& render_target, const CXVec4& color);
	void clearDepthStencil(const  CXTexture2DPtr& depth_stencil);

	void setRenderTarget(const  CXTexture2DPtr& render_target, const  CXTexture2DPtr& depth_stencil);

	void setVertexBuffer(const  CXVertexBufferPtr& buffer);
	void setIndexBuffer(const  CXIndexBufferPtr& buffer);


	void drawTriangleList(ui32 vertex_count, ui32 start_vertex_index);
	void drawIndexedTriangleList(ui32 index_count, ui32 start_vertex_index, ui32 start_index_location);
	void drawTriangleStrip(ui32 vertex_count, ui32 start_vertex_index);

	void setViewportSize(ui32 width, ui32 height);
	void setShader(const  CXShaderPtr& shader);
	void setConstantBuffer(const  CXConstantBufferPtr& buffer);
	void setRasterizerState(bool cull_front);


	void setTexture(const  CXTexturePtr* texture, unsigned int num_textures);
	void setMaterial(const  CXMaterialPtr& material);
	void drawMesh(const  CXMeshPtr& mesh, const std::vector<CXMaterialPtr>& list_materials);
private:
	void compilePrivateShaders();
	void initRasterizerState();

private:
	Microsoft::WRL::ComPtr < ID3D11Device> m_d3dDevice;
	Microsoft::WRL::ComPtr < IDXGIDevice> m_dxgiDevice;
	Microsoft::WRL::ComPtr < IDXGIAdapter> m_dxgiAdapter;
	Microsoft::WRL::ComPtr < IDXGIFactory> m_dxgiFactory;
	Microsoft::WRL::ComPtr < ID3D11DeviceContext> m_immContext;
private:
	Microsoft::WRL::ComPtr <ID3D11RasterizerState> m_cullFrontState;
	Microsoft::WRL::ComPtr <ID3D11RasterizerState> m_cullBackState;

	unsigned char m_meshLayoutByteCode[1024];
	size_t m_meshLayoutSize = 0;

private:
	friend class  CXSwapChain;
	friend class  CXVertexBuffer;
	friend class  CXIndexBuffer;
	friend class  CXConstantBuffer;
	friend class  CXVertexShader;
	friend class  CXPixelShader;
	friend class  CXTexture2D;
	friend class  CXShader;
}