#include "Enemy.h"
#include "MochinekoEngine/BoxCollider.h"
#include "Bullet.h"

void Enemy::Init() {
	fbx_ = new FBX("Asset/Enemy.fbx");
	fbx_->Init();

	auto collider = new BoxCollider(this, {2.0f, 3.0f, 1.0f});
	collider->Init();
	colliderList_.push_back(collider);
}

void Enemy::Update() {
	fbx_->SetTransform(transform_);
	fbx_->UpdateTransform();
	fbx_->Update();
}

void Enemy::Draw() {
	fbx_->DrawImGUI();
	fbx_->Draw();
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
