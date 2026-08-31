#include "Bullet.h"
#include "MochinekoEngine/ObjectManager.h"

void Bullet::Init() {
	fbx_ = new FBX("Asset/Bullet.fbx");
	fbx_->Init();

	transform_.velocity_ = {0, 0, 0.1};
}

void Bullet::Update() {
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
