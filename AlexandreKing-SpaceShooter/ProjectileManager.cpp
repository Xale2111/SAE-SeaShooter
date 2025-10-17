#include "ProjectileManager.h"

#include <iostream>

void ProjectileManager::Load(std::string projectileSpritePath)
{
	playerProjectile_.Load(projectileSpritePath);
}


void ProjectileManager::AddProjectile(Vector2f projectileStartPosition, Vector2f projectileDirection)
{
	Projectile newProjectile(playerProjectile_);
	newProjectile.SetPosition(projectileStartPosition);
	newProjectile.SetDirection(projectileDirection);
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
