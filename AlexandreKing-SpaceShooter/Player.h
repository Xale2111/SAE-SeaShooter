#pragma once
#include <numbers>

#include "Entity.h"
#include "Projectile.h"
#include "ProjectileManager.h"
constexpr float angle1 = 12.5;
constexpr float angleR1 = (90 + angle1) * std::numbers::pi / 180.f;
constexpr float angleL1 = (90 - angle1) * std::numbers::pi / 180.f;

constexpr float angle2 = 25.f;
constexpr float angleR2 = (90 + angle2) * std::numbers::pi / 180.f;
constexpr float angleL2 = (90 - angle2) * std::numbers::pi / 180.f;


class Player : public Entity
{
private:
	int score_;

	Vector2f leftDir1 = { cos(angleL1) ,-sin(angleL1) };
	Vector2f rightDir1 = { cos(angleR1) ,-sin(angleR1)};

	Vector2f leftDir2 = { cos(angleL2) ,-sin(angleL2) };
	Vector2f rightDir2 = { cos(angleR2) ,-sin(angleR2) };

	bool isShooting = false;

	Time deltaTime;
	float shootingDelay = 0.15f;
	int bulletAmount = 1;

	CircleShape hitbox_;


	void SetHitboxSize() override;

public:
	using Entity::Entity;
	void Shoot(Time deltaTime);
	void SetIsShooting(bool shooting);

};

