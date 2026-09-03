#pragma once
#include <Windows.h>

namespace MochinekoEngine {

	HWND GetGameWindowHandle();
	bool CanShutdown();
	void Shutdown();
	float GetDeltaTime();
}

namespace MochinekoEngineResource {
	inline int sphereColHandle_ = -1;
	inline int boxColHandle_ = -1;

	void Init();
}