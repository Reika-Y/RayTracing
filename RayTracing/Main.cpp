#include <windows.h>
#include "Director.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Director::GetInstance().Run();
	return 0;
}
