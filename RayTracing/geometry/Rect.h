#pragma once
#include "Vector2D.h"

///矩形を表す構造体
struct Rect {
	Rect() : pos(0, 0), width(0), height(0) {}
	Rect(float x, float y, int inw, int inh) : pos(x, y), width(inw), height(inh) {}
	Rect(Position2& inpos, int inw, int inh) : pos(inpos), width(inw), height(inh) {}

	void SetCenter(float x, float y);
	void SetCenter(const Position2& inpos);
	Vector2 Center();
	float Left() { return pos.x - width / 2; }
	float Top() { return pos.y - height / 2; }
	float Right() { return pos.x + width / 2; }
	float Bottom() { return pos.y + height / 2; }

	Position2 pos;			//中心座標
	int width, height;		//幅,高さ
};
