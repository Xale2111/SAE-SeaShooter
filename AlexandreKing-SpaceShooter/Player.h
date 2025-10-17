#pragma once
#include "Entity.h"
#include "Projectile.h"
#include "ProjectileManager.h"
class Player : public Entity
{
private:
	int score_;
public:
	using Entity::Entity;
	void Shoot();

};

