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

bool RayTrace::IsHitRayAndObject(const Position3f& eye, const Vector3f& ray, const Sphere& sp, Vector3f& normal)
{
	auto distance = [&](float a, float b) {
		return sqrt(-pow(a, 2) + pow(b, 2));
	};
	auto sight = sp._pos - eye;
	auto baseRange = Dot(sight, ray);
	auto base = ray * baseRange;
	auto vec = base - sight;
	if (sp._radius >= vec.Magnitude())
	{
		auto t = baseRange - distance(vec.Magnitude(), sp._radius);
		auto hitPos = eye + ray * t;
		normal = hitPos - sp._pos;
		normal.Normalize();
		return true;
	}
	return false;
}

void RayTrace::DrawPixelWithFloat(int x, int y, float r, float g, float b)
{
	DrawPixel(x, y, GetColor(r * 0xff, g * 0xff, b * 0xff));
}

void RayTrace::RayTracing(const Position3f& eye, const Sphere& sp)
{
	Vector3f light = Vector3f(-1, 1, 1).Normalized();

	for (int y = 0; y < _screenSize.height; y++)
	{
		for (int x = 0; x < _screenSize.width; x++)
		{
			// 視線ベクトル
			auto sight = Vector3f(x - _screenSize.width / 2, _screenSize.height / 2 - y, 0) - eye;
			sight.Normalize();
			Vector3f normal;
			if (IsHitRayAndObject(eye, sight, sp, normal))
			{
				auto diffuse = Clamp(Dot(light, normal));

				DrawPixelWithFloat(x, y, diffuse, diffuse, diffuse);
			}
			else
			{
				DrawPixelWithFloat(x, y, 0.4, 0.9, 1);
			}
		}
	}
}

float RayTrace::Clamp(float in, const float min, const float max)
{
	return max(min(in, max), min);
}
