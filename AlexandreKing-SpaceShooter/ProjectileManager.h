#pragma once
#include <SFML/Graphics.hpp>
#include "Projectile.h"

class ProjectileManager
{
private:
	uint64_t projectileCounter;
	Projectile playerProjectile_;
	std::vector<Projectile> allProjectiles_;
	std::vector<Projectile> projectilesToRemove_;
public:
	void Load(std::string projectileSpritePath);
	void AddProjectile(Vector2f projectileStartPosition, Vector2f projectileDirection);
	void AddProjectileToRemoveList(Projectile* projectileToDestroy);
	void RemoveProjectiles();
	std::vector<Projectile>& GetAllProjectiles();

};

