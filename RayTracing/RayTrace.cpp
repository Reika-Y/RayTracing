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
				// 基本色
				Color albedo = { 1.f,0.7f,0.7f };
				// 拡散反射
				auto diffuse = Dot(light, normal);
				diffuse = (0 <= diffuse ? diffuse: 0);
				albedo *= diffuse;
				// 反射
				auto reflect = 2.f * normal * diffuse - light;
				// 反射光(スペキュラ)
				float specular = 1 * pow(Dot(reflect, sight), 20) * 1;
				Color color = { Clamp(albedo.x + specular),Clamp(albedo.y + specular) ,Clamp(albedo.z + specular)};
				DrawPixelWithFloat(x, y, color.x, color.y, color.z);
			}
			else
			{
				// 床との判定
				auto plane = Plane{ Vector3f(0,1,0), -10 };
				if (Dot(plane._normal, sight) < 0)
				{
					auto t = (plane._offset - Dot(eye, plane._normal)) / Dot(sight, plane._normal);
					auto hitPos = eye + sight * t;
					if (static_cast<int>(hitPos.x + _screenSize.width * 10 )/2 % 2 == 0 )
					{
						if (static_cast<int>(hitPos.z + _screenSize.height * 10)/2 % 2 == 0)
						{
							DrawPixelWithFloat(x, y, 1, 1, 1);
						}
						else
						{
							DrawPixelWithFloat(x, y, 1, 0.07, 0.5);
						}
					}
					else
					{
						if (static_cast<int>(hitPos.z + _screenSize.height * 4)/2 % 2 == 1)
						{
							DrawPixelWithFloat(x, y, 1, 1, 1);
						}
						else
						{
							DrawPixelWithFloat(x, y, 1, 0.07, 0.5);
						}
					}
				}
				else
				{
					DrawPixelWithFloat(x, y, 0.4, 0.9, 1);
				}
			}
		}
	}
}

float RayTrace::Clamp(float in, const float min, const float max)
{
	return max(min(in, max), min);
}
