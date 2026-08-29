#pragma once
#include "MochinekoEngine/BaseObject.h"

class Bullet : public BaseObject{
private:
public:

	Bullet() 
		: BaseObject("Bullet") {
	};

	~Bullet() {};

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

