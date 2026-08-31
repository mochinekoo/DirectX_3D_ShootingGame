#pragma once
#include <Windows.h>

namespace MochinekoEngine {

	HWND GetGameWindowHandle();
	bool CanShutdown();
	void Shutdown();
}