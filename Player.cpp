#include "Player.h"
#include "MochinekoEngine/FBX.h"
#include "MochinekoEngine/InputManager.h"
#include "Bullet.h"
#include "MochinekoEngine/ObjectManager.h"

void Player::Init() {
	fbx_ = new FBX("Asset/Player.fbx");
	fbx_->Init();
}

void Player::Update() {
	if (InputManager::CheckDownKey(DIK_SPACE)) {
		Bullet* bullet = new Bullet();
		ObjectManager::AddObject(bullet);
	}

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
