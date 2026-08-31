#include "RunningScene.h"
#include "MochinekoEngine/InputManager.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "MochinekoEngine/ObjectManager.h"
#include "MochinekoEngine/DX2DManager.h"
#include "MochinekoEngine/FontText.h"
#include "MochinekoEngine/CameraManager.h"

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

}

void RunningScene::Draw()
{
}
