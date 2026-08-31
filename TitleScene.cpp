#include "TitleScene.h"
#include "MochinekoEngine/ObjectManager.h"
#include "MochinekoEngine/Image.h"
#include "MochinekoEngine/FBX.h"
#include "MochinekoEngine/SceneManager.h"

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
	if (startButton_->IsPush()) {
		SceneManager::ChangeScene("RunningScene");
	}
	if (exitButton_->IsPush()) {
		MochinekoEngine::Shutdown();
	}
}

void TitleScene::Draw() {
}
