#pragma once
#include "Vector3D.h"

// 球を表す構造体
struct Sphere {
	Sphere() :_radius(0), _pos(0,0,0) {}
	Sphere(float r, Position3f p):_radius(r), _pos(p) {}
	float _radius;		// 半径
	Position3f _pos;	// 座標
};