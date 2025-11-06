#include "Enemy.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include "BoxCollider.h"

void Enemy::SetRotation(Vector2f direction)
{
	float angleRadians = atan2(direction.y, direction.x);
	float angleDegrees = angleRadians * 180 / M_PI;
	rotate(degrees(angleDegrees-90));
}

void Enemy::Destroy()
{
	state_ = ObjectState::kDestroyed;
}

Enemy::Enemy(int healthPoint, int damage, float spriteScale, EntityType type, float shootingDelay, int shootingAmount, int pointValue, Vector2f direction, float speed, uint64_t ID)
: Entity(healthPoint, damage, spriteScale, type), shootingDelay_(shootingDelay), shootingAmount_(shootingAmount), pointValue_(pointValue), direction_(direction),speed_(speed), ID_(ID)
{
	shootingDelay_ = shootingDelay;
	shootingAmount_ = shootingAmount;
	pointValue_ = pointValue;
	direction_ = direction;
	speed_ = speed;
	ID_ = ID;
	layer_ = ObjectLayer::kEnemy;
}

void Enemy::DefineAnimation(std::string spritePath, float animationSpeed)
{
	normalAnimation_.Load(spritePath, animationSpeed);
	SetAnimation(normalAnimation_, 0);
}

void Enemy::Shoot()
{
	if (shootDeltaTime_.asSeconds() > shootingDelay_)
	{
		if (shootingAmount_ >= 1)
		{
			//Center Laser
			projectileManager_->AddProjectile({ getPosition().x, getPosition().y }, direction_, type_, damage_);
		}
		if (shootingAmount_ >= 3)
		{
			//first side lasers
			projectileManager_->AddProjectile({ getPosition().x, getPosition().y }, direction_-leftDir1, type_, damage_);
			projectileManager_->AddProjectile({ getPosition().x, getPosition().y }, direction_ - rightDir1, type_, damage_);
		}
		if (shootingAmount_ >= 5)
		{
			//second side lasers
			projectileManager_->AddProjectile({ getPosition().x, getPosition().y }, direction_ - leftDir2, type_, damage_);
			projectileManager_->AddProjectile({ getPosition().x, getPosition().y }, direction_ - rightDir2, type_, damage_);
		}
		audioManager_->PlayLaserSoundEffect();
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


void Enemy::SetDeltaTime(Time deltaTime)
{
	shootDeltaTime_ += deltaTime;
	moveDeltaTime_ = deltaTime;
}

void Enemy::SetCollider(float rotation)
{
	Vector2f hitboxSize = Vector2f(GetAnimationTexture().getSize().x, GetAnimationTexture().getSize().y) * spriteScale_;

	BoxCollider* newCollider = new BoxCollider();
	newCollider->InstanciateNewBoxCollider(hitboxSize, 1.15f, getRotation().asDegrees());

	collider_ = *newCollider;
}

ObjectState Enemy::GetState()
{
	return state_;
}

void Enemy::SetID(uint64_t newID)
{
	ID_ = newID;
}
uint64_t Enemy::GetID()
{
	return ID_;
}

int Enemy::GetPointValue()
{
	return pointValue_;
}

void Enemy::DetectCollision()
{
	for (auto& projectile : projectileManager_->GetAllProjectiles())
	{
		if (projectile.GetLayer() == ObjectLayer::kPlayerProjectile)
		{
			if (collider_.GetHitboxRef().getGlobalBounds().findIntersection(projectile.GetHitbox().GetHitboxRef().getGlobalBounds()))
			{
				projectile.Destroy();
				TakeDamage(projectile.GetDamage());
				if (GetHealthPoints() <= 0)
				{
					Destroy();
				}
			}
		}
	}
}
