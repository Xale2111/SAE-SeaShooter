#pragma once
#include "Entity.h"

using namespace sf;

class Enemy : public Entity
{
private:
	float shootingDelay_;
	int shootingAmount_;
	int pointValue_;
	Time moveDeltaTime_;
	Time shootDeltaTime_;
	Vector2f direction_;
	float speed_;
	uint64_t ID_;

	RectangleShape hitbox_;


	void SetRotation(Vector2f direction);

	void SetHitboxSize() override;

public:
	Enemy(std::string spritesPath, float animSpeed, int healthPoint, int damage, float spriteScale,EntityType type,float shootingDelay, int shootingAmount, int pointValue, Vector2f direction, float speed, uint64_t ID);
	void Shoot();
	void Move();
	void SetPosition(Vector2f newPosition);
	void SetDirection(Vector2f newDirection);
	void SetID(uint64_t newID);
	void SetDeltaTime(Time deltaTime);
};

