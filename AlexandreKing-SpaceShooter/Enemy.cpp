#include "Enemy.h"

#include <iostream>

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
	if (shootingClock_.getElapsedTime().asSeconds() > shootingDelay_)
	{
		shootingClock_.restart();
		for (int i = 0; i < shootingAmount_; ++i)
		{
			projectileManager_->AddProjectile({ getPosition().x, getPosition().y}, direction_, type_);
		}
	}
}

void Enemy::Move()
{
	deltaTime = movingClock_.restart();
	//Stops the enemy at y >= 500 so the player can shoot them
	std::cout << "Enemy ID : " << ID_ << " Y position :  " << getPosition().y << std::endl;
	if (direction_.length() != 0 && getPosition().y <300)
	{
		SetPosition(getPosition() + direction_.normalized() * speed_ * deltaTime.asSeconds());
	}
}

void Enemy::SetPosition(Vector2f newPosition)
{
	setPosition(newPosition);
}

void Enemy::SetDirection(Vector2f newDirection)
{
	direction_ = newDirection;
}

void Enemy::SetID(uint64_t newID)
{
	ID_ = newID;
}


