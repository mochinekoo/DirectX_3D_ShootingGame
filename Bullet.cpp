#include "Bullet.h"
#include "MochinekoEngine/ObjectManager.h"
#include "MochinekoEngine/SphereCollider.h"
#include "MochinekoEngine/ModelManager.h"
#include "RunningScene.h"
#include "GameGlobal.h"

using namespace GameModel;

namespace {
	const float DEFAULT_LIFETIME = 10.0f;
}

void Bullet::Init() {
	lifeTime_ = DEFAULT_LIFETIME;

	//transform_.velocity_ = {0, 0, 0.1};

	AddCollider(new SphereCollider(this, 1.0f));
}

void Bullet::Update() {
	//lifeTime_ -= 0.1f;
	FBX* model = ModelManager::GetModel(bulletHandle_);

	if (lifeTime_ <= 0.0f) {
		KillMe();
		return;
	}

	transform_.location_.x += transform_.velocity_.x;
	transform_.location_.y += transform_.velocity_.y;
	transform_.location_.z += transform_.velocity_.z;

	model->SetTransform(transform_);
	model->UpdateTransform();
	model->Update();
}

void Bullet::Draw() {
	FBX* model = ModelManager::GetModel(bulletHandle_);
	model->DrawImGUI();
	model->Draw();
}

void Bullet::Release()
{
}
