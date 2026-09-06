#include "TitleScene.h"
#include "MochinekoEngine/ObjectManager.h"
#include "MochinekoEngine/Image.h"
#include "MochinekoEngine/FBX.h"
#include "MochinekoEngine/SceneManager.h"
#include "MochinekoEngine/MathUtil.h"

void TitleScene::Init() {
	startButton_ = new ImageButton("Asset/StartButton.png");
	startButton_->SetTag("StartButton");
	startButton_->SetLocation({395, 110, 0});
	ObjectManager::AddObject(startButton_);
	exitButton_ = new ImageButton("Asset/ExitButton.png");
	exitButton_->SetTag("ExitButton");
	exitButton_->SetLocation({395, 470, 0});
	ObjectManager::AddObject(exitButton_);
}

void TitleScene::Update() {
	static float nextTime = 0.0f;
	static bool nextScene = false;
	

	if (!actionLock_) {
		if (startButton_->IsPush()) {
			actionLock_ = true;
			nextScene = true;
		}
		if (exitButton_->IsPush()) {
			MochinekoEngine::Shutdown();
		}

		startButton_->GetImage()->SetGray((!startButton_->IsHover()));
		exitButton_->GetImage()->SetGray((!exitButton_->IsHover()));
	}
	else {
		if (nextScene) {
			Color color = MochinekoEngine::GetBackgroundColor();
			float rate = nextTime / 5.0f;

			auto easeing = MathUtil::easeOutQuad;
			float r = MathUtil::Lerp(color.r_, Color::Black().r_, rate, easeing);
			float g = MathUtil::Lerp(color.g_, Color::Black().g_, rate, easeing);
			float b = MathUtil::Lerp(color.b_, Color::Black().b_, rate, easeing);
			float a = MathUtil::Lerp(color.a_, 0.0f, rate, easeing);


			MochinekoEngine::SetBackgroundColor({r, g, b, a});
			if (rate >= 1.0f) {
				MochinekoEngine::SetBackgroundColor(Color::White());
				SceneManager::ChangeScene("RunningScene");
			}

			nextTime += MochinekoEngine::GetDeltaTime();
		}
	}
}

void TitleScene::Draw() {
}
