#pragma once
#include "MochinekoEngine/BaseObject.h"
#include "MochinekoEngine/FBX.h"

class Enemy : public BaseObject{
private:
	FBX* fbx_;
public:

	Enemy()
		: BaseObject("Enemy") {
		fbx_ = nullptr;
	};

	~Enemy() {};

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

