#pragma once
#include "MochinekoEngine/BaseObject.h"

class Player : public BaseObject {
private:
public:

	Player()
		: BaseObject("Player") {

	}

	~Player() {}

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;

};

