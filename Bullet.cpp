#include "Bullet.h"
#include "MochinekoEngine/ObjectManager.h"
#include "MochinekoEngine/SphereCollider.h"
#include "MochinekoEngine/ModelManager.h"
#include "RunningScene.h"

namespace {
	const float DEFAULT_LIFETIME = 10.0f;
}

void Bullet::Init() {
	lifeTime_ = DEFAULT_LIFETIME;

	transform_.velocity_ = {0, 0, 0.1};

	auto collider = new SphereCollider(this, 5.0f);
	collider->Init();
	colliderList_.push_back(collider);
}

void Bullet::Update() {
	//lifeTime_ -= 0.1f;
	FBX* model = ModelManager::GetModel(RunningSceneModel::bulletHandle_);

	if (lifeTime_ <= 0.0f) {
		KillMe();
		return;
	}

	transform_.location_.z += transform_.velocity_.z;

	model->SetTransform(transform_);
	model->UpdateTransform();
	model->Update();
}

void Bullet::Draw() {
	FBX* model = ModelManager::GetModel(RunningSceneModel::bulletHandle_);
	model->DrawImGUI();
	model->Draw();
}

void Bullet::Release()
{
}
