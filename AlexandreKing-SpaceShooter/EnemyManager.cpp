#include "EnemyManager.h"


void EnemyManager::Spawn()
{
	//enemyWavePrediction[0];

}

void EnemyManager::DefineEnemies(Enemy* easyEnemy, Enemy* mediumEnemy, Enemy* hardEnemy, Enemy* hardcoreEnemy)
{
	easyEnemy_ = easyEnemy;
	mediumEnemy_ = mediumEnemy;
	hardEnemy_ = hardEnemy;
	hardcoreEnemy_ = hardcoreEnemy;
}

void EnemyManager::AddEnemy(int chooseEnemy)
{
	int randEnemy = chooseEnemy;

	if (chooseEnemy < 0)
	{
		randEnemy = rand() % 4;
	}
	Enemy* newEnemy = easyEnemy_;


	switch (randEnemy)
	{
	case 0:
		newEnemy = easyEnemy_;
		break;

	case 1:
		newEnemy = mediumEnemy_;
		break;

	case 2:
		newEnemy = hardEnemy_;
		break;

	case 3:
		newEnemy = hardcoreEnemy_;
		break;

	default:
		newEnemy = easyEnemy_;
		break;
	}

	float positionX = rand() % 1920;
	Vector2f direction(0,1);
	Angle directionAngle;
	newEnemy->SetPosition({positionX,-50});
	if (positionX <300)
	{
		directionAngle =degrees(-45);
		direction.x = 1;
	}
	else if (positionX >1620)
	{
		directionAngle = degrees(45);
		direction.x = -1;
	}
	else
	{
		directionAngle = degrees(0);
	}
	newEnemy->SetDirection(direction);
	newEnemy->rotate(directionAngle);
	

	allEnemies_.emplace_back(newEnemy);

}

std::vector<Enemy*> EnemyManager::GetAllEnemies()
{
	return allEnemies_;
}

void EnemyManager::SetEnemyWaveEasy()
{
	//Define the waves 
	enemyWavePrediction.insert(std::pair<Enemy,EnemyFormation>(*easyEnemy_, EnemyFormation::SingleMiddle));
}
