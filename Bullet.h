#pragma once
#include "MochinekoEngine/BaseObject.h"
#include "MochinekoEngine/FBX.h"

class Bullet : public BaseObject{
private:
	FBX* fbx_;
public:

	Bullet() 
		: BaseObject("Bullet") {
		fbx_ = nullptr;
	};

	~Bullet() {};

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

