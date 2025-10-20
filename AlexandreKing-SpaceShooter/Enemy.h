#pragma once
#include "Entity.h"

using namespace sf;

class Enemy : public Entity
{
private:
	Clock shootingClock_;
	Clock movingClock_;
	float shootingDelay_;
	int shootingAmount_;
	int pointValue_;
	Time deltaTime;
	Vector2f direction_;
	float speed_;

public:
	Enemy(std::string spritesPath, float animSpeed, int healthPoint, int damage, float spriteScale,EntityType type,float shootingDelay, int shootingAmount, int pointValue, Vector2f direction, float speed);
	void Shoot();
	void Move();
	void SetPosition(Vector2f newPosition);
	void SetDirection(Vector2f newDirection);
};

