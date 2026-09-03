#include "RunningScene.h"
#include "MochinekoEngine/InputManager.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "MochinekoEngine/ObjectManager.h"
#include "MochinekoEngine/DX2DManager.h"
#include "MochinekoEngine/FontText.h"
#include "MochinekoEngine/CameraManager.h"
#include "MochinekoEngine/ModelManager.h"
#include "MochinekoEngine/SceneManager.h"

void RunningScene::Init() {
	Camera* camera = CameraManager::GetCurrentCamera();
	camera->postion_ = {0, 15, -30};
	camera->target_ = { 0, 0, 0 };

	Player* player = new Player();
	player->SetLocation({0, 0, -15});
	ObjectManager::AddObject(player);

	Enemy* enemy = new Enemy();
	ObjectManager::AddObject(enemy);
}

void RunningScene::Update() {
	auto enemyList = ObjectManager::FindObjects<Enemy>();
	bool canFinish = enemyList.empty() || gameTime_ <= 0;
	if (canFinish) {
		SceneManager::ChangeScene("EndingScene");
	}

	gameTime_ -= MochinekoEngine::GetDeltaTime();
}

void RunningScene::Draw() {
	char leftText[255] = {};
	sprintf_s(leftText, sizeof(leftText), "残り時間：%.0f 秒", gameTime_);
	DX2DManager::DrawFontText(0, 0, leftText, {0, 0, 0, 1});
}
