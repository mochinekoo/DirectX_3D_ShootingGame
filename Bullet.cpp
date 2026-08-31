#include "Bullet.h"
#include "MochinekoEngine/ObjectManager.h"

void Bullet::Init() {
	fbx_ = new FBX("Asset/Bullet.fbx");
	fbx_->Init();
}

void Bullet::Update() {
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
