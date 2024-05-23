#pragma once


enum class EProjectionMode
{
	PERSPECTIVE = 0,
	ORTHOGRAPHIC
};

enum class ELightType
{
	DIRECTIONAL,
	POINT,
	SPOT,
	RECT
};

enum class EVolumetricLightType
{
	SPHERE,
	CUBE
};