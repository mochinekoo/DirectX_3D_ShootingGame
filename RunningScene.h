#pragma once
#include "MochinekoEngine/BaseScene.h"

namespace {
	inline const float DEFAULT_GAMETIME = 30.0f;
}

class RunningScene : public BaseScene {
private:
	float gameTime_;
public:

	RunningScene()
		: BaseScene("RunningScene") {
		gameTime_ = DEFAULT_GAMETIME;
	}

	~RunningScene() {}

	void Init() override;
	void Update() override;
	void Draw() override;
};

