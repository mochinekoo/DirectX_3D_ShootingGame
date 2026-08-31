#pragma once
#include "MochinekoEngine/BaseObject.h"
#include "MochinekoEngine/FBX.h"

class Player : public BaseObject {
private:
	FBX* fbx_;
public:

	Player()
		: BaseObject("Player") {
		fbx_ = nullptr;
	}

	~Player() {}

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;

};

