#pragma once
#include "geometry/Geometry.h"

// レイトレーイングを実際に行うクラス
class RayTrace
{
public:
	RayTrace(Size& _size);
	~RayTrace();
	void Update(void);
private:
	bool IsHitRayAndObject(const Position3f& eye, const Vector3f& ray, const Sphere& sp);
	void DrawPixelWithFloat(int x, int y, float r, float g, float b);
	void RayTracing(const Position3f& eye, const Sphere& sp);

	Size _screenSize;
};

