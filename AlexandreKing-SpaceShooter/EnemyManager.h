#pragma once
#include "Enemy.h"
#include "Player.h"

const std::string enemiesSpritesPath = "assets/sprites/enemy/";

enum class EnemyFormation
{
	kSingleLeft,			//1 unit from top left
	kSingleMiddle,		//1 unit from top middle
	kSingleRight,		//1 unit from top right
	kDuoLeft,			//2 units from top left
	kDuoMiddle,			//2 units from top middle
	kDuoRight,			//2 units from top right
	kTriangleLeft,		//3 units from top left
	kTriangleMiddle,		//3 units from top middle
	kTriangleRight,		//3 units from top right
	kBigTriangleLeft,	//5 units from top left
	kBigTriangleMiddle,	//5 units from top middle
	kBigTriangleRight	//5 units from top right
};

class EnemyManager
{
private:
	std::vector<Enemy> allEnemies_;

	//first pair = enemy difficulty and formation, float is the delay between two enemy spawning
	std::vector<std::pair<std::pair<Enemy*, EnemyFormation>,float>> enemyWavePrediction;

	//Create template of enemy (green-> easy, blue-> medium, red-> hard, Yellow-> HARDCORE)
	Enemy* easyEnemy_;
	Enemy* mediumEnemy_;
	Enemy* hardEnemy_;
	Enemy* hardcoreEnemy_;

	int currentWaveIndex_ = 0;

	Clock clock_;
	Time waveDelay;


	void SetEnemyWaveEasy();
	void SetEnemyWaveMedium();
	void SetEnemyWaveHard();
	void SetEnemyWaveHardcore();

public:
	void SetAllWaves();
	void Spawn();
	void DefineEnemies(Enemy* easyEnemy, Enemy* mediumEnemy, Enemy* hardEnemy, Enemy* hardcoreEnemy);
	//Spawn enemy at random possible position
	void AddEnemy(Enemy* enemy,Vector2f startPosition);
	std::vector<Enemy>& GetAllEnemies();


};

