#pragma once
#include "Texture2D.h"

struct TextureCubeDesc
{

};

class MTextureCube : public MTexture2D
{
public:
	MTextureCube(const wchar_t* filePath);
	MTextureCube(const TextureCubeDesc texture2DDesc);

protected:

};