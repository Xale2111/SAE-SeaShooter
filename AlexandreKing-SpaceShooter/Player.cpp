#include "Player.h"

void Player::Shoot()
{
	//TODO : Make that a power up later on, rotate projectile in the direction
	/*
	projectileManager_->AddProjectile({ getPosition().x, getPosition().y - GetTextureSize().y / 2 }, { -1,-1 });
	projectileManager_->AddProjectile({ getPosition().x, getPosition().y - GetTextureSize().y / 2 }, { 1,-1 });
	*/
	//Center Laser
	projectileManager_->AddProjectile({getPosition().x, getPosition().y},{0,-1}, type_);
	audioManager_->PlayLaserSoundEffect();
}
