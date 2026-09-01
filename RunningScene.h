#pragma once
#include "MochinekoEngine/BaseScene.h"

namespace RunningSceneModel {
	inline int sphereColHandle_ = -1;
	inline int bulletHandle_ = -1;
}

class RunningScene : public BaseScene {
private:
public:

	RunningScene()
		: BaseScene("RunningScene") {
		RunningSceneModel::bulletHandle_ = -1;
		RunningSceneModel::sphereColHandle_ = -1;
	}

	~RunningScene() {}

	void Init() override;
	void Update() override;
	void Draw() override;
};

