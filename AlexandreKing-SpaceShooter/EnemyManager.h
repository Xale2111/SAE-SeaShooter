#pragma once
#include "Enemy.h"

const std::string enemiesSpritesPath = "assets/sprites/enemy/";

enum class EnemyFormation
{
	SingleLeft,			//1 unit from top left
	SingleMiddle,		//1 unit from top middle
	SingleRight,		//1 unit from top right
	DuoLeft,			//2 units from top left
	DuoMiddle,			//2 units from top middle
	DuoRight,			//2 units from top right
	TriangleLeft,		//3 units from top left
	TriangleMiddle,		//3 units from top middle
	TriangleRight,		//3 units from top right
	BigTriangleLeft,	//5 units from top left
	BigTriangleMiddle,	//5 units from top middle
	BigTriangleRight	//5 units from top right
};

class EnemyManager
{
private:
	std::vector<Enemy*> allEnemies_;

	std::unordered_map<Enemy, EnemyFormation> enemyWavePrediction;

	//Create template of enemy (green-> easy, blue-> medium, red-> hard, Yellow-> HARDCORE)
	Enemy* easyEnemy_;
	Enemy* mediumEnemy_;
	Enemy* hardEnemy_;
	Enemy* hardcoreEnemy_;

	int currentWaveIndex_ = 0;

public:
	void Spawn();
	void DefineEnemies(Enemy* easyEnemy, Enemy* mediumEnemy, Enemy* hardEnemy, Enemy* hardcoreEnemy);
	//Spawn enemy at random possible position
	void AddEnemy(int chooseEnemy = -1);
	std::vector<Enemy*> GetAllEnemies();

	void SetEnemyWaveEasy();
	void SetEnemyWaveMedium();
	void SetEnemyWaveHard();

};

