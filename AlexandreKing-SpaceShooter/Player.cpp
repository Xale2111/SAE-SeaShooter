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
	if (score_ > 1000)
	{
		bulletAmount = 2;
	}
	if (score_ > 6000)
	{
		bulletAmount = 4;
	}
	if (score_ > 20000)
	{
		bulletAmount = 6;
	}
	if (score_ > 40000)
	{
		bulletAmount = 7;
	}

	/*
	if (score_/10000*(healthBoostCounter+1) >= 1)
	{
		if (healthBoostCounter < MAX_HEALTH_BOOST)
		{
			SetHealthPoints(playerDefaultHealth + 100);
		}
		else
		{
			if (GetHealthPoints()+50 < )
			{
				
			}
			SetHealthPoints(GetHealthPoints() + 50);
		}
		healthBoostCounter++;
	}*/

}

void Player::ResetInvicibility()
{
	invicibilityTime = invicibilityTime.Zero;
}

void Player::DefineAll(MeteorManager* manager, std::string normalSpritesPath, float normalSpeed, std::string invincibleSpritesPath, float invincibleSpeed)
{
	DefineLayer();
	DefineMeteorManager(manager);
	normalAnimation_.Load(normalSpritesPath, normalSpeed);
	invincibleAnimation_.Load(invincibleSpritesPath, invincibleSpeed);
	SetAnimation(normalAnimation_, 0);
	invicibilityTime += seconds(5);
}

void Player::Shoot(Time dt)
{
	if (isShooting && shootingDelay < deltaTime.asSeconds())
	{
		deltaTime = deltaTime.Zero;


		if (bulletAmount == 1 || bulletAmount >=7)
		{
			//Center Laser
			projectileManager_->AddProjectile({ getPosition().x, getPosition().y }, { 0,-1 }, type_, damage_);

		}
		if (bulletAmount >= 2)
		{
			//Center Laser
			projectileManager_->AddProjectile({ getPosition().x + 20, getPosition().y }, { 0,-1 }, type_, damage_);
			projectileManager_->AddProjectile({ getPosition().x - 20, getPosition().y }, { 0,-1 }, type_, damage_);
		}
		if (bulletAmount >= 4)
		{
			//first side lasers
			projectileManager_->AddProjectile({ getPosition().x+10, getPosition().y }, leftDir1, type_, damage_);
			projectileManager_->AddProjectile({ getPosition().x-10, getPosition().y }, rightDir1, type_, damage_);
		}
		if (bulletAmount >= 6)
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
	if (!isInvicible)
	{
		for (auto& projectile : projectileManager_->GetAllProjectiles())
		{
			if (projectile.GetLayer() == ObjectLayer::kEnemyProjectile)
			{
				if (collider_.GetHitboxRef().getGlobalBounds().findIntersection(projectile.GetHitbox().GetHitboxRef().getGlobalBounds()))
				{
					projectile.Destroy();
					TakeDamage(projectile.GetDamage());
					isInvicible = true;
					ResetInvicibility();
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
					isInvicible = true;
					ResetInvicibility();
				}
			}
		}
	}
}


void Player::MakePlayerInvicible(Time deltaTime)
{
	if (invicibilityTime.asSeconds() < invicibilityDelay)
	{
		SetAnimation(invincibleAnimation_, GetAnimationIndex());
	}
	else
	{
		SetAnimation(normalAnimation_, GetAnimationIndex());
		isInvicible = false;
	}
	invicibilityTime += deltaTime;
}

void Player::AddScore(int pointGained)
{
	score_ += pointGained;
	UpgradeWithScore();
}

int Player::GetScore()
{
	return score_;
}

void Player::Reset(int defaultHeathPoints)
{
	score_ = 0;
	isShooting = false;
	ResetInvicibility();
	isInvicible = false;
	SetAnimation(normalAnimation_, GetAnimationIndex());
	bulletAmount = 1;
	ResetHealthPoint(defaultHeathPoints);
	
}
