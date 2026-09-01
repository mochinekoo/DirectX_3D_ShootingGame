#include "SphereCollider.h"
#include <DirectXMath.h>
#include "../RunningScene.h"
#include "ModelManager.h"

using namespace DirectX;
using namespace RunningSceneModel;

void SphereCollider::Init() {
	FBX* model = ModelManager::GetModel(sphereColHandle_);
	Transform transform = model->GetTransform();
	transform.scale_ = {radius_, radius_, radius_};
	model->SetTransform(transform);
	model->SetWireframe(true);
}

void SphereCollider::Update() {
	Transform parentTransform = parent_->GetTransform();
    transform_.location_ = parentTransform.location_;
	transform_.scale_ = { radius_, radius_, radius_ };

	FBX* model = ModelManager::GetModel(sphereColHandle_);
	model->SetTransform(transform_);
	model->UpdateTransform();
	model->Update();
}

void SphereCollider::Draw() {
	ModelManager::GetModel(sphereColHandle_)->Draw();
}

bool SphereCollider::IsHitSphereSphere(SphereCollider* col1, SphereCollider* col2) {
    if (col1 != nullptr && col2 != nullptr) {
		XMFLOAT3 aPos = col1->transform_.location_;
		XMFLOAT3 bPos = col2->transform_.location_;
		XMVECTOR vectorA = XMLoadFloat3(&aPos);
		XMVECTOR vectorB = XMLoadFloat3(&bPos);

		XMVECTOR diff = XMVectorSubtract(vectorA, vectorB);
		float distance = XMVectorGetX(XMVector3Length(diff));
		return distance < (col1->GetRadius() + col2->GetRadius());
    }

    return false;
}
