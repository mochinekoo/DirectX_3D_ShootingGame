#include "Enemy.h"
#include "MochinekoEngine/BoxCollider.h"
#include "Bullet.h"
#include "MochinekoEngine/ModelManager.h"
#include "GameGlobal.h"

using namespace GameModel;

void Enemy::Init() {
	AddCollider(new BoxCollider(this, { 2.0f, 3.0f, 1.0f }));
}

void Enemy::Update() {
	FBX* fbx = ModelManager::GetModel(enemyHandle_);
	fbx->SetTransform(transform_);
	fbx->UpdateTransform();
	fbx->Update();
}

void Enemy::Draw() {
	FBX* fbx = ModelManager::GetModel(enemyHandle_);
	fbx->DrawImGUI();
	fbx->Draw();
}

void Enemy::Release()
{
}

void Enemy::OnCollision(BaseObject* object) {
	Bullet* bullet = dynamic_cast<Bullet*>(object);
	if (bullet != nullptr) {
		KillMe();
		bullet->KillMe();
	}
}
