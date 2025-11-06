#include "Player.h"

#include <iostream>

#include "CircleCollider.h"

void Player::DefineLayer()
{
	layer_ = ObjectLayer::kPlayer;
}

void Player::DefineMeteorManager(MeteorManager* manager)
{
	meteorManager_ = manager;
}

void Player::UpgradeWithScore()
{
	if (score_ > 300)
	{
		bulletAmount = 3;
	}
	if (score_ > 500)
	{
		bulletAmount = 5;
	}
}

void Player::DefineAll(MeteorManager* manager)
{
	DefineLayer();
	DefineMeteorManager(manager);
}

void Player::Shoot(Time dt)
{
	if (isShooting && shootingDelay < deltaTime.asSeconds())
	{
		deltaTime = deltaTime.Zero;

		if (bulletAmount >= 1)
		{
			//Center Laser
			projectileManager_->AddProjectile({ getPosition().x+20, getPosition().y }, { 0,-1 }, type_, damage_);
			projectileManager_->AddProjectile({ getPosition().x-20, getPosition().y }, { 0,-1 }, type_, damage_);
		}
		if (bulletAmount >= 3)
		{
			//first side lasers
			projectileManager_->AddProjectile({ getPosition().x+10, getPosition().y }, leftDir1, type_, damage_);
			projectileManager_->AddProjectile({ getPosition().x-10, getPosition().y }, rightDir1, type_, damage_);
		}
		if (bulletAmount >= 5)
		{
			//second side lasers
			projectileManager_->AddProjectile({ getPosition().x+10, getPosition().y }, leftDir2, type_, damage_);
			projectileManager_->AddProjectile({ getPosition().x-10, getPosition().y }, rightDir2, type_, damage_);
		}
		audioManager_->PlayLaserSoundEffect();
	}
	deltaTime += dt;
}

void Player::SetIsShooting(bool shooting)
{
	isShooting = shooting;
}

void Player::SetCollider(float rotation)
{
	//if player scale is 1f, radius is 150.f
	float radius = 150.f * spriteScale_;
	Vector2f origin = Vector2f(getPosition().x + radius, (getPosition().y + radius / 2));

	CircleCollider* newCollider = new CircleCollider();
	newCollider->InstanciateNewCircleCollider(radius, origin, 0.8f);


	collider_ = *newCollider;
}

void Player::DetectCollision()
{
	for (auto& projectile : projectileManager_->GetAllProjectiles())
	{
		if (projectile.GetLayer() == ObjectLayer::kEnemyProjectile)
		{
			if (collider_.GetHitboxRef().getGlobalBounds().findIntersection(projectile.GetHitbox().GetHitboxRef().getGlobalBounds()))
			{
				projectile.Destroy();
				TakeDamage(projectile.GetDamage());
			}
		}
	}
	for (auto& meteor : meteorManager_->GetAllMeteors())
	{
		if (meteor.GetLayer() == ObjectLayer::kMeteor)
		{
			if (collider_.GetHitboxRef().getGlobalBounds().findIntersection(meteor.GetHitbox().GetHitboxRef().getGlobalBounds()))
			{
				meteor.Destroy();
				TakeDamage(20);
				audioManager_->PlayCollisionSoundEffect();
			}
		}
	}
}


void Player::AddScore(int pointGained)
{
	score_ += pointGained;
	UpgradeWithScore();
}
