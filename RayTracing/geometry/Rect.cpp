#include "Rect.h"

void Rect::SetCenter(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

void Rect::SetCenter(const Position2& inpos)
{
	pos.x = inpos.x;
	pos.y = inpos.y; 
}

Vector2 Rect::Center()
{
	return pos;
}
