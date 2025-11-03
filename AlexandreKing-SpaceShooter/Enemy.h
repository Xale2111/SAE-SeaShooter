#pragma once
#include "Entity.h"

#include "ObjectState.h"

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

	ObjectState state_ = ObjectState::kNone;

	void SetRotation(Vector2f direction);
	void Destroy();
public:
	Enemy(std::string spritesPath, float animSpeed, int healthPoint, int damage, float spriteScale,EntityType type,float shootingDelay, int shootingAmount, int pointValue, Vector2f direction, float speed, uint64_t ID);
	void Shoot();
	void Move();
	void SetPosition(Vector2f newPosition);
	void SetDirection(Vector2f newDirection);
	void SetDeltaTime(Time deltaTime);
	void SetCollider(float rotation = 0) override;

	ObjectState GetState();

	void SetID(uint64_t newID);
	uint64_t GetID();

	int GetPointValue();

	void DetectCollision() override;

};

