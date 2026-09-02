#pragma once
#include "MochinekoEngine/BaseScene.h"

class EndingScene : public BaseScene {
private:
	int counter_;
public:

	EndingScene()
		: BaseScene("EndingScene") {
		counter_ = 0;
	}

	~EndingScene() {}

	void Init() override;
	void Update() override;
	void Draw() override;

};

