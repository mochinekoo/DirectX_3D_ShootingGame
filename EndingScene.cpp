#include "EndingScene.h"
#include "MochinekoEngine/DX2DManager.h"
#include "MochinekoEngine/SceneManager.h"
#include "MochinekoEngine/Framework.h"

namespace {
	const float NEXT_SCENE_TIME = 10.0f;
}

void EndingScene::Init() {
	counter_ = 0;
}

void EndingScene::Update() {
	if (counter_ >= NEXT_SCENE_TIME) {
		SceneManager::ChangeScene("TitleScene");
	}

	counter_ += MochinekoEngine::GetDeltaTime();
}

void EndingScene::Draw() {
	DX2DManager::DrawFontText(0, 0, "ゲーム終了!", {0, 0, 0, 1});
}
