#pragma once

#include "Entity.h"
#include "MeteorManager.h"
#include "Projectile.h"
#include "ProjectileManager.h"


class Player : public Entity
{
private:
	int score_;

	bool isShooting = false;
	bool isInvicible = false;

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
	void DefineAll(MeteorManager* manager, std::string normalSpritesPath, float normalSpeed, std::string invincibleSpritesPath, float invincibleSpeed);
	void Shoot(Time deltaTime);
	void SetIsShooting(bool shooting);
	void SetCollider(float rotation = 0) override;
	void DetectCollision() override;

	void MakePlayerInvicible(Time deltaTime);

	void AddScore(int pointGained);
	int GetScore();

	void Reset(int defaultHeathPoints);

};

