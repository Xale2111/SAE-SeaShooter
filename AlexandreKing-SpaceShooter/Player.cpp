#include "Player.h"

void Player::SetHitboxSize()
{
	float radius = 60.f;
	hitbox_.setRadius(radius);
	Vector2f origin = Vector2f(getPosition().x+radius, getPosition().y + radius/2);
	hitbox_.setOrigin(origin);

	SetHitbox(&hitbox_, 0.8f);
}

void Player::Shoot(Time dt)
{
	if (isShooting && shootingDelay < deltaTime.asSeconds())
	{
		deltaTime = deltaTime.Zero;

		if (bulletAmount == 1)
		{
			//Center Laser
			projectileManager_->AddProjectile({ getPosition().x, getPosition().y }, { 0,-1 }, type_);
		}
		if (bulletAmount == 3)
		{
			//first side lasers
			projectileManager_->AddProjectile({ getPosition().x, getPosition().y }, leftDir1, type_);
			projectileManager_->AddProjectile({ getPosition().x, getPosition().y }, rightDir1, type_);
		}
		if (bulletAmount == 5)
		{
			//second side lasers
			projectileManager_->AddProjectile({ getPosition().x, getPosition().y }, leftDir2, type_);
			projectileManager_->AddProjectile({ getPosition().x, getPosition().y }, rightDir2, type_);
		}
		audioManager_->PlayLaserSoundEffect();
	}
	deltaTime += dt;
}

void Player::SetIsShooting(bool shooting)
{
	isShooting = shooting;
}