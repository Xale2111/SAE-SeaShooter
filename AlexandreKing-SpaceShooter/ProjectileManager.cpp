#include "ProjectileManager.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

void ProjectileManager::Load()
{
	playerProjectile_.Load(ProjectileSpritesPath + "player");
	enemyProjectile_.Load(ProjectileSpritesPath+"enemy");
}


void ProjectileManager::AddProjectile(Vector2f projectileStartPosition, Vector2f projectileDirection, EntityType entityType)
{
	Projectile newProjectile;
	switch (entityType)
	{
	case EntityType::kPlayer:
		newProjectile = playerProjectile_;
		break;
	case EntityType::kEasyEnemy:
	case EntityType::kMediumEnemy:
	case EntityType::kHardEnemy:
	case EntityType::kHardcoreEnemy:
		newProjectile = enemyProjectile_;
		break;
	}


	newProjectile.CenterOrigin();

	newProjectile.SetDirection(projectileDirection);

	/*Angle directionAngle;
	if (projectileDirection.x < 0)
	{
		directionAngle = degrees(45);
	}
	else if (projectileDirection.x > 0)
	{
		directionAngle = degrees(-45);
	}
	else
	{
		directionAngle = degrees(0);
	}
	newProjectile.setRotation(directionAngle);*/


	newProjectile.SetPosition(projectileStartPosition);

    newProjectile.SetID(projectileCounter++);

	allProjectiles_.emplace_back(newProjectile);
}

void ProjectileManager::AddProjectileToRemoveList(Projectile* projectileToDestroy)
{
	projectilesToRemove_.push_back(*projectileToDestroy);
}

void ProjectileManager::RemoveProjectiles()
{
    allProjectiles_.erase(std::remove_if(allProjectiles_.begin(),allProjectiles_.end(),
            [&](Projectile& p) {
                return std::any_of(projectilesToRemove_.begin(),projectilesToRemove_.end(),[&](Projectile& r) {
                        return p.GetID() == r.GetID();
                    });
            }),
        allProjectiles_.end());
    
}

std::vector<Projectile>& ProjectileManager::GetAllProjectiles()
{
	return  allProjectiles_;
}
