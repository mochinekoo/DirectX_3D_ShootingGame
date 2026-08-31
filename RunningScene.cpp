#include "RunningScene.h"
#include "MochinekoEngine/InputManager.h"
#include "Bullet.h"
#include "Enemy.h"
#include "MochinekoEngine/ObjectManager.h"
#include "MochinekoEngine/DX2DManager.h"
#include "MochinekoEngine/FontText.h"

void RunningScene::Init() {
}

void RunningScene::Update() {
	if (InputManager::CheckDownKey(DIK_SPACE)) {
		Bullet* bullet = new Bullet();
		ObjectManager::AddObject(bullet);
	}

	if (InputManager::CheckDownKey(DIK_E)) {
		Enemy* enemy = new Enemy();
		ObjectManager::AddObject(enemy);
	}
}

void RunningScene::Draw()
{
}
