#include "Player.h"
#include "MochinekoEngine/FBX.h"
#include "MochinekoEngine/InputManager.h"
#include "Bullet.h"
#include "MochinekoEngine/ObjectManager.h"
#include "MochinekoEngine/BoxCollider.h"
#include "MochinekoEngine/ModelManager.h"
#include "GameGlobal.h"

using namespace GameModel;
using namespace DirectX;

void Player::Init() {
	transform_.velocity_ = {0.1, 0, 0.1};

	AddCollider(new BoxCollider(this, { 8.0f, 2.0f, 5.0f }));
}

void Player::Update() {
	FBX* fbx = ModelManager::GetModel(playerHandle_);
	if (InputManager::CheckDownKey(DIK_SPACE) || InputManager::IsControllerButtonPush(XINPUT_GAMEPAD_A)) {
		Bullet* bullet = new Bullet();
		bullet->SetLocation(transform_.location_);
		XMMATRIX world = fbx->GetWorldMatrix();
		XMVECTOR forward = XMVector3TransformNormal(
			XMVectorSet(0, 0, 1, 0),
			XMMatrixRotationRollPitchYaw(transform_.rotation_.x, transform_.rotation_.y, transform_.rotation_.z)
		);
		float speed = 0.1f;
		XMVECTOR velocity = forward * speed;
		XMFLOAT3 bulletVelocity = {};
		XMStoreFloat3(&bulletVelocity, velocity);
		bullet->SetVelocity(bulletVelocity);
		ObjectManager::AddObject(bullet);
	}
	if (InputManager::CheckDownKey(DIK_Y) || InputManager::IsControllerButtonPush(XINPUT_GAMEPAD_Y)) {
		transform_.rotation_ = { 0, 0, 0 };
	}

	if (InputManager::CheckPushKey(DIK_LEFT) || InputManager::GetControllerTiltLeft().x <= -32767 * 0.5) {
		transform_.location_.x -= transform_.velocity_.x;
	}
	if (InputManager::CheckPushKey(DIK_RIGHT) || InputManager::GetControllerTiltLeft().x >= 32767 * 0.5) {
		transform_.location_.x += transform_.velocity_.x;
	}

	if (InputManager::CheckPushKey(DIK_A) || InputManager::GetControllerTiltRight().x <= -32767 * 0.5) {
		transform_.rotation_.x -= DirectX::XMConvertToRadians(1.0f);
	}
	if (InputManager::CheckPushKey(DIK_D) || InputManager::GetControllerTiltRight().x >= 32767 * 0.5) {
		transform_.rotation_.x += DirectX::XMConvertToRadians(1.0f);
	}
	if (InputManager::CheckPushKey(DIK_W) || InputManager::GetControllerTiltRight().y <= -32767 * 0.5) {
		transform_.rotation_.y -= DirectX::XMConvertToRadians(1.0f);
	}
	if (InputManager::CheckPushKey(DIK_S) || InputManager::GetControllerTiltRight().y >= 32767 * 0.5) {
		transform_.rotation_.y += DirectX::XMConvertToRadians(1.0f);
	}

	
	fbx->SetTransform(transform_);
	fbx->UpdateTransform();
	fbx->Update();
}

void Player::Draw() {
	FBX* fbx = ModelManager::GetModel(playerHandle_);
	fbx->DrawImGUI();
	fbx->Draw();
}

void Player::Release()
{
}
