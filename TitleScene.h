#pragma once
#include "MochinekoEngine/BaseScene.h"
#include "MochinekoEngine/ImageButton.h"

class TitleScene : public BaseScene {
private:
	bool actionLock_;
	ImageButton* startButton_;
	ImageButton* exitButton_;
public:

	TitleScene()
		: BaseScene("TitleScene") {
		startButton_ = nullptr;
		exitButton_ = nullptr;
		actionLock_ = false;
	}

	~TitleScene() {};

	void Init() override;
	void Update() override;
	void Draw() override;

};

