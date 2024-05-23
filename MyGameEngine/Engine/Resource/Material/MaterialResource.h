#pragma once
#include "../Resource.h"

class MMaterialResource : public MResource
{
public:
	MMaterialResource(const wchar_t* full_path, CXResourceManager* manager);
	MMaterialResource(const  CXMaterialPtr& material, CXResourceManager* manager);

	void addTexture(const  CXTexturePtr& texture);
	void removeTexture(unsigned int index);

	void setData(void* data, unsigned int size);
	void setUserData(void* data, unsigned int size);

	void setCullMode(const  CXCullMode& mode);
	CXCullMode getCullMode();
private:
	CXShaderPtr m_shader;
	CXConstantBufferPtr m_constant_buffer;
	CXConstantBufferPtr m_userBuffer;
	std::vector<CXTexturePtr> m_vec_textures;
	CXCullMode m_cull_mode = CXCullMode::Back;
};