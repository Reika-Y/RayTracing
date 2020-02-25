#pragma once
#include "Vector2D.h"

// 円を表す構造体
struct Circle {
	Circle():radius(0),pos(0,0){}
	Circle(float r, Position2f& p):radius(r),pos(p) {}

	float radius;		// 半径
	Position2f pos;		// 中心座標
};

