#pragma once
#include "Vector3D.h"

// 平面を表す構造体
struct Plane
{
	Vector3f _normal;		// 法線
	float _offset;			// 原点からのオフセット
};