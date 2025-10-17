#include "Enemy.h"

Enemy::Enemy(std::string spritesPath, float animSpeed, int healthPoint, int damage, float spriteScale, float shootingDelay, int shootingAmount, int pointValue, Vector2f direction, float speed)
: Entity(spritesPath, animSpeed, healthPoint, damage, spriteScale), shootingDelay_(shootingDelay), shootingAmount_(shootingAmount), pointValue_(pointValue), direction_(direction),speed_(speed)
{
	shootingDelay_ = shootingDelay;
	shootingAmount_ = shootingAmount;
	pointValue_ = pointValue;
	direction_ = direction;
	speed_ = speed;
}


void Enemy::Shoot()
{
	if (shootingClock_.getElapsedTime().asSeconds() > shootingDelay_)
	{
		shootingClock_.restart();
		for (int i = 0; i < shootingAmount_; ++i)
		{
			projectileManager_->AddProjectile({ getPosition().x, getPosition().y - GetTextureSize().y / 2 }, { 0,1 });
		}
	}
}

void Enemy::Move()
{
	deltaTime = movingClock_.restart();
	Vector2f newPosition{getPosition()};
	if (direction_.length() >0)
	{
		newPosition = getPosition() + direction_.normalized() * speed_ * deltaTime.asSeconds();
	}

	setPosition(newPosition);
}

void Enemy::SetPosition(Vector2f newPosition)
{
	setPosition(newPosition);
}

void Enemy::SetDirection(Vector2f newDirection)
{
	direction_ = newDirection;
}
