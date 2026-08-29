#pragma once
#include "MochinekoEngine/BaseObject.h"

class Enemy : public BaseObject{
private:
public:

	Enemy()
		: BaseObject("Enemy") {
	};

	~Enemy() {};

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

