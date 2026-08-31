#pragma once
#include "MochinekoEngine/BaseObject.h"
#include "MochinekoEngine/FBX.h"

class Bullet : public BaseObject{
private:
	FBX* fbx_;
	float lifeTime_;
public:

	Bullet() 
		: BaseObject("Bullet") {
		fbx_ = nullptr;
		lifeTime_ = 0.0f;
	};

	~Bullet() {};

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

