#include <cmath>
#include <DxLib.h>
#include "RayTrace.h"

RayTrace::RayTrace(Size& _size)
{
	_screenSize = _size;
}

RayTrace::~RayTrace()
{
}

void RayTrace::Update(void)
{
	RayTracing(Vector3f(0, 0, 300), Sphere(100, Position3f(0, 0, -100)));
}

bool RayTrace::IsHitRayAndObject(const Position3f& eye, const Vector3f& ray, const Sphere& sp)
{
	auto oc = eye - sp._pos;
	float a = Dot(ray, ray);
	float b = 2.0f * Dot(ray, oc);
	float c = Dot(oc, oc) - pow(sp._radius, 2);
	// 判別式
	float D = b * b - 4 * a * c;
	return (D > 0);
}

void RayTrace::DrawPixelWithFloat(int x, int y, float r, float g, float b)
{
	DrawPixel(x, y, GetColor(r * 0xff, g * 0xff, b * 0xff));
}

void RayTrace::RayTracing(const Position3f& eye, const Sphere& sp)
{
	for (int y = 0; y < _screenSize.height; y++)
	{
		for (int x = 0; x < _screenSize.width; x++)
		{
			// 視線ベクトル
			auto sight = Vector3f(x - _screenSize.width / 2, _screenSize.height / 2 - y, 0) - eye;
			sight.Normalize();
			if (IsHitRayAndObject(eye, sight, sp))
			{
				DrawPixelWithFloat(x, y, 1, 1, 1);
			}
			else
			{
				DrawPixelWithFloat(x, y, 0.4, 0.9, 1);
			}
		}
	}
}
