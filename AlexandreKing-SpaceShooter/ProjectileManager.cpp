#include "ProjectileManager.h"

void ProjectileManager::Load()
{
	playerProjectile_.Load(PROJECTILE_SPRITES_PATH + "player");
	enemyProjectile_.Load(PROJECTILE_SPRITES_PATH + "enemy/all");
	hardEnemyProjectile_.Load(PROJECTILE_SPRITES_PATH+"enemy/hard");
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
		newProjectile = enemyProjectile_;
		break;
	case EntityType::kHardEnemy:
	case EntityType::kHardcoreEnemy:
		newProjectile = hardEnemyProjectile_;
		break;
	}

	//center the projectile so it's origin is now in the center
	newProjectile.CenterOrigin();

	newProjectile.SetDirection(projectileDirection);

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
