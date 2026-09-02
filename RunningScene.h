#pragma once
#include "MochinekoEngine/BaseScene.h"

namespace RunningSceneModel {
	inline int sphereColHandle_ = -1;
	inline int bulletHandle_ = -1;
}

namespace {
	inline const float DEFAULT_GAMETIME = 30.0f;
}

class RunningScene : public BaseScene {
private:
	float gameTime_;
public:

	RunningScene()
		: BaseScene("RunningScene") {
		RunningSceneModel::bulletHandle_ = -1;
		RunningSceneModel::sphereColHandle_ = -1;
		gameTime_ = DEFAULT_GAMETIME;
	}

	~RunningScene() {}

	void Init() override;
	void Update() override;
	void Draw() override;
};

