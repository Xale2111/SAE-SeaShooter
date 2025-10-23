#include "Enemy.h"

#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

void Enemy::SetRotation(Vector2f direction)
{

	float angleRadians = atan2(direction.y, direction.x);
	float angleDegrees = angleRadians * 180 / M_PI;
	rotate(degrees(angleDegrees-90));
}

Enemy::Enemy(std::string spritesPath, float animSpeed, int healthPoint, int damage, float spriteScale, EntityType type, float shootingDelay, int shootingAmount, int pointValue, Vector2f direction, float speed, uint64_t ID)
: Entity(spritesPath, animSpeed, healthPoint, damage, spriteScale, type), shootingDelay_(shootingDelay), shootingAmount_(shootingAmount), pointValue_(pointValue), direction_(direction),speed_(speed), ID_(ID)
{
	shootingDelay_ = shootingDelay;
	shootingAmount_ = shootingAmount;
	pointValue_ = pointValue;
	direction_ = direction;
	speed_ = speed;
	ID_ = ID;
}


void Enemy::Shoot()
{
	if (shootDeltaTime_.asSeconds() > shootingDelay_)
	{
		for (int i = 0; i < shootingAmount_; ++i)
		{
			projectileManager_->AddProjectile({ getPosition().x, getPosition().y}, direction_, type_);
			audioManager_->PlayLaserSoundEffect();
		}
		shootDeltaTime_ = Time(seconds(0));
	}
}

void Enemy::Move()
{
	//Stops the enemy at y >= 500 so the player can shoot them
	if (direction_.length() != 0 && getPosition().y <300)
	{
		SetPosition(getPosition() + direction_.normalized() * speed_* moveDeltaTime_.asSeconds());
	}
}

void Enemy::SetPosition(Vector2f newPosition)
{
	setPosition(newPosition);
}

void Enemy::SetDirection(Vector2f newDirection)
{
	direction_ = newDirection;
	SetRotation(direction_);
}

void Enemy::SetID(uint64_t newID)
{
	ID_ = newID;
}

void Enemy::SetDeltaTime(Time deltaTime)
{
	shootDeltaTime_ += deltaTime;
	moveDeltaTime_ = deltaTime;
}
