#pragma once
#include "geometry/Geometry.h"
#include "RayTrace.h"

class Director
{
public:
	static Director& GetInstance();
	void Run(void);
	const Size& GetWinSize(void);
private:
	Director();
	Director(const Director&) {};
	~Director();
	void operator = (const Director&) {};

	int Init(void);

	Size _winSize;
	RayTrace *_rayTrace;
};

