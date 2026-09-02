#include "BoxCollider.h"
#include "Transform.h"

using namespace DirectX;

void BoxCollider::Init() {
	fbx_->Init();
	fbx_->SetWireframe(true);
	Transform transform = fbx_->GetTransform();
	transform.scale_ = colliderSize_;
	fbx_->SetTransform(transform);
}

void BoxCollider::Update() {
	Transform parentTransform = parent_->GetTransform();
	transform_.location_ = parentTransform.location_;
	transform_.scale_ = colliderSize_;

	fbx_->SetTransform(transform_);
	fbx_->UpdateTransform();
	fbx_->Update();
}

void BoxCollider::Draw() {
	fbx_->Draw();
}

bool BoxCollider::IsHitBoxBox(BoxCollider* colA, BoxCollider* colB) {
	if (colA != nullptr && colB != nullptr) {
		XMFLOAT3 locA = colA->transform_.location_;
		XMFLOAT3 sizeA = colA->GetColliderSize();
		XMFLOAT3 locB = colB->transform_.location_;
		XMFLOAT3 sizeB = colB->GetColliderSize();
		bool hitX = locA.x < locB.x + sizeB.x && locA.x + sizeA.x > locB.x;
		bool hitY = locA.y < locB.y + sizeB.y && locA.y + sizeA.y > locB.y;
		bool hitZ = locA.z < locB.z + sizeB.z && locA.z + sizeA.z > locB.z;
		return hitX && hitY && hitZ;
	}
	return false;
}

bool BoxCollider::IsHitBoxSphere(BoxCollider* col1, SphereCollider* col2) {
	if (col1 != nullptr && col2 != nullptr) {
		XMFLOAT3 spherePos = col2->GetTransform().location_;
		XMFLOAT3 boxPos = col1->transform_.location_;
		float sphereRadius = col2->GetRadius();

		XMVECTOR sphereVector = XMLoadFloat3(&spherePos);
		XMVECTOR boxVector = XMLoadFloat3(&boxPos);

		XMFLOAT3 boxSize = col1->GetColliderSize();
		XMVECTOR boxHalfSize = XMVectorSet(boxSize.x / 2.0f, boxSize.y / 2.0f, boxSize.z / 2.0f, 0.0f);

		XMVECTOR minBox = XMVectorSubtract(boxVector, boxHalfSize);
		XMVECTOR maxBox = XMVectorAdd(boxVector, boxHalfSize);
		XMVECTOR closestPoint = XMVectorClamp(sphereVector, minBox, maxBox);
		XMVECTOR diff = XMVectorSubtract(sphereVector, closestPoint);
		float distance = XMVectorGetX(XMVector3LengthSq(diff));
		return distance < (sphereRadius * sphereRadius);
	}
}
