#pragma once
#include <SFML/Graphics.hpp>

#include "Projectile.h"
#include "EntityType.h"

class ProjectileManager
{
private:
	uint64_t projectileCounter;
	Projectile playerProjectile_;
	Projectile enemyProjectile_;
	Projectile hardEnemyProjectile_;
	std::vector<Projectile> allProjectiles_;
	std::vector<Projectile> projectilesToRemove_;
public:
	void Load();
	void AddProjectile(Vector2f projectileStartPosition, Vector2f projectileDirection, EntityType entityType, int damage);
	void AddProjectileToRemoveList(Projectile* projectileToDestroy);
	void RemoveProjectiles();
	std::vector<Projectile>& GetAllProjectiles();

	void Reset();
};

