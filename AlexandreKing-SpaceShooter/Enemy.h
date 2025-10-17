#pragma once
#include "Entity.h"

class Enemy : Entity
{
private:
	Clock clock_;
	float shootingDelay_;
	int shootingAmount_;
	int pointValue_;

public:
	using Entity::Entity;
	void Shoot();
	void Move();

};

