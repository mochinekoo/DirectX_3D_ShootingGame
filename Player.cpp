#include "Player.h"
#include "MochinekoEngine/FBX.h"
#include "MochinekoEngine/InputManager.h"
#include "Bullet.h"
#include "MochinekoEngine/ObjectManager.h"
#include "MochinekoEngine/BoxCollider.h"

void Player::Init() {
	fbx_ = new FBX("Asset/Player.fbx");
	fbx_->Init();

	transform_.velocity_ = {0.1, 0, 0.1};

	auto collider = new BoxCollider(this, { 8.0f, 2.0f, 5.0f });
	collider->Init();
	colliderList_.push_back(collider);
}

void Player::Update() {
	if (InputManager::CheckDownKey(DIK_SPACE) || InputManager::IsControllerButtonPush(XINPUT_GAMEPAD_A)) {
		Bullet* bullet = new Bullet();
		bullet->SetLocation(transform_.location_);
		ObjectManager::AddObject(bullet);
	}

	if (InputManager::CheckPushKey(DIK_LEFT) || InputManager::GetControllerTiltLeft().x <= -32767 * 0.5) {
		transform_.location_.x -= transform_.velocity_.x;
	}
	if (InputManager::CheckPushKey(DIK_RIGHT) || InputManager::GetControllerTiltLeft().x >= 32767 * 0.5) {
		transform_.location_.x += transform_.velocity_.x;
	}

	fbx_->SetTransform(transform_);
	fbx_->UpdateTransform();
	fbx_->Update();
}

void Player::Draw() {
	fbx_->DrawImGUI();
	fbx_->Draw();
}

void Player::Release()
{
}
