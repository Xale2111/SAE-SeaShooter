#include "Enemy.h"

void Enemy::Shoot()
{
	for (int i = 0; i < shootingAmount; ++i)
	{
		projectileManager_->AddProjectile({ getPosition().x, getPosition().y - GetTextureSize().y / 2 }, {0,1});
	}
}
