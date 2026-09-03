#include "GameGlobal.h"
#include "MochinekoEngine/ModelManager.h"

void GameModel::Init() {
	bulletHandle_ = ModelManager::Load("Asset/Bullet.fbx");
	enemyHandle_ = ModelManager::Load("Asset/Enemy.fbx");
	playerHandle_ = ModelManager::Load("Asset/Player.fbx");
}
