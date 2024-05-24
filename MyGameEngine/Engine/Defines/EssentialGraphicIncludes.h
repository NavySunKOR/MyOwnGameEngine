#pragma once
#include <d3d11.h>
#include <wrl.h>
#include <d3dcompiler.h>
#include <directxtk/SimpleMath.h>
#include <directxtk/DDSTextureLoader.h> 
#include <directxtk/WICTextureLoader.h>


//멀티플랫폼 사용을 위해서는 방식을 변경하여야하지만 지금은 Direct X 하나만 다룬다는 전제 조건으로 간다. 멀티플랫폼이 어쩌구 저쩌구 하면 돌아가는 엔진조차 못만듬.
using namespace DirectX;
using namespace DirectX::SimpleMath;