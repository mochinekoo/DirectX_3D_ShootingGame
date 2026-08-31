#include "Enemy.h"

void Enemy::Init() {
	fbx_ = new FBX("Asset/Enemy.fbx");
	fbx_->Init();
}

void Enemy::Update() {
	fbx_->SetTransform(transform_);
	fbx_->UpdateTransform();
	fbx_->Update();
}

void Enemy::Draw() {
	fbx_->Draw();
}

void Enemy::Release()
{
}
