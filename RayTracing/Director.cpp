#include "Director.h"
#include <DxLib.h>

Director& Director::GetInstance()
{
	static Director task;
	return task;
}

void Director::Run(void)
{
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		(*_rayTrace).Update();
	}
}

// ウィンドウサイズを返す
const Size& Director::GetWinSize(void)
{
	return _winSize;
}

Director::Director()
{
	Init();
	_rayTrace = new RayTrace(_winSize);
}

Director::~Director()
{
	delete(_rayTrace);
	DxLib_End();
}

// 初期化
int Director::Init(void)
{
	_winSize.width = 640;
	_winSize.height = 480;
	ChangeWindowMode(true);
	SetGraphMode(static_cast<int>(_winSize.width), static_cast<int>(_winSize.height), 32);
	SetMainWindowText(_T("RayTracing"));
	DxLib_Init();
	return true;
}
