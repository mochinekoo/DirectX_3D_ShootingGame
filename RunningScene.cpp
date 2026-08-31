#include "RunningScene.h"
#include "MochinekoEngine/InputManager.h"
#include "Bullet.h"
#include "MochinekoEngine/ObjectManager.h"

void RunningScene::Init() {
}

void RunningScene::Update() {
	if (InputManager::CheckDownKey(DIK_SPACE)) {
		Bullet* bullet = new Bullet();
		ObjectManager::AddObject(bullet);
	}
}

void RunningScene::Draw()
{
}
