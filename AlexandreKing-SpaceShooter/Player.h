#pragma once

#include "Entity.h"
#include "MeteorManager.h"
#include "Projectile.h"
#include "ProjectileManager.h"

const int playerDefaultHealth = 250;

class Player : public Entity
{
private:
	int score_;

	bool isShooting = false;
	bool isInvicible = false;

	const int MAX_HEALTH_BOOST = 5;
	int healthBoostCounter = 0;

	float invicibilityDelay = 3.f;
	Time invicibilityTime;

	Time deltaTime;
	float shootingDelay = 0.2f;
	int bulletAmount = 1;

	MeteorManager* meteorManager_;

	Animation invincibleAnimation_;
	Animation normalAnimation_;

	void DefineLayer();
	void DefineMeteorManager(MeteorManager* manager);

	void UpgradeWithScore();

	void ResetInvicibility();

public:
	using Entity::Entity;
	void DefineAll(MeteorManager* manager, float normalSpeed, float invincibleSpeed);
	void Shoot(Time deltaTime);
	void SetIsShooting(bool shooting);
	void SetCollider(float rotation = 0) override;
	void DetectCollision() override;

	void MakePlayerInvicible(Time deltaTime);
	void UpdateAnimation(Time deltaTime);

	void AddScore(int pointGained);
	int GetScore();

	void Reset(int defaultHeathPoints);

};

