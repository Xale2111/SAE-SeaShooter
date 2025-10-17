#include "Player.h"




void Player::Shoot()
{
	
	projectileManager_->AddProjectile({ getPosition().x, getPosition().y - GetTextureSize().y / 2 }, { -1,-1 });
	projectileManager_->AddProjectile({ getPosition().x, getPosition().y - GetTextureSize().y / 2 }, { 1,-1 });

	//Center Laser
	projectileManager_->AddProjectile({getPosition().x, getPosition().y-GetTextureSize().y/2},{0,-1});
}
