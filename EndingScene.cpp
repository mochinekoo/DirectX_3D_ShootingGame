#include "EndingScene.h"
#include "MochinekoEngine/DX2DManager.h"
#include "MochinekoEngine/SceneManager.h"

void EndingScene::Init() {
	counter_ = 0;
}

void EndingScene::Update() {
	if (counter_ == 300) {
		SceneManager::ChangeScene("TitleScene");
	}

	counter_++;
}

void EndingScene::Draw() {
	DX2DManager::DrawFontText(0, 0, "ゲーム終了!", {0, 0, 0, 1});
}
