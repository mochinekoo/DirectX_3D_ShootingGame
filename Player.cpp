#include "Player.h"
#include "MochinekoEngine/FBX.h"

void Player::Init() {
	fbx_ = new FBX("Asset/Player.fbx");
	fbx_->Init();
}

void Player::Update() {
	fbx_->SetTransform(transform_);
	fbx_->UpdateTransform();
	fbx_->Update();
}

void Player::Draw() {
	fbx_->Draw();
}

void Player::Release()
{
}
