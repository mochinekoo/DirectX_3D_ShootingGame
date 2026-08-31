#include "Bullet.h"
#include "MochinekoEngine/ObjectManager.h"

namespace {
	const float DEFAULT_LIFETIME = 10.0f;
}

void Bullet::Init() {
	fbx_ = new FBX("Asset/Bullet.fbx");
	fbx_->Init();
	lifeTime_ = DEFAULT_LIFETIME;

	transform_.velocity_ = {0, 0, 0.1};
}

void Bullet::Update() {
	lifeTime_ -= 0.1f;

	if (lifeTime_ <= 0.0f) {
		KillMe();
		return;
	}

	transform_.location_.z += transform_.velocity_.z;

	fbx_->SetTransform(transform_);
	fbx_->UpdateTransform();
	fbx_->Update();
}

void Bullet::Draw() {
	fbx_->Draw();
}

void Bullet::Release()
{
}
