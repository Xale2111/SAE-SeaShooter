#pragma once
#include "Enemy.h"

class EnemyManager
{
private:
	std::vector<Enemy*> allEnemies;
	
	//Create template of enemy (green-> easy, blue-> medium, red-> hard, Yellow-> HARDCORE)

public:
	//Spawn enemy at random possible position
	void SpawnEnemy();

};

