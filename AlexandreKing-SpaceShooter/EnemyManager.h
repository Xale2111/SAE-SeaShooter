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
	std::vector<std::pair<std::pair<EntityType, EnemyFormation>,float>> enemyWavePrediction;

	//Create template of enemy (green-> easy, blue-> medium, red-> hard, Yellow-> HARDCORE)
	Enemy easyEnemy_ = Enemy(enemiesSpritesPath + "easy/", 0.2f, 50, 10, 0.4f, EntityType::kEasyEnemy, 1, 1, 20, { 0,0 }, 100, -1);
	Enemy mediumEnemy_ = Enemy(enemiesSpritesPath + "medium/", 0.2f, 100, 25, 1, EntityType::kEasyEnemy, 0.5, 1, 50, { 0,0 }, 110, -1);
	Enemy hardEnemy_ = Enemy(enemiesSpritesPath + "hard/", 0.2f, 200, 35, 0.35f, EntityType::kEasyEnemy, 0.75, 3, 100, { 0,0 }, 125, -1);
	Enemy hardcoreEnemy_ = Enemy(enemiesSpritesPath + "hardcore/", 0.2f, 500, 50, 1, EntityType::kEasyEnemy, 0.5, 5, 250, { 0,0 }, 80, -1);

	uint64_t enemyID;

	int currentWaveIndex_ = 0;

	Clock clock_;
	Time waveDelay;


	void SetEnemyWaveEasy();
	void SetEnemyWaveMedium();
	void SetEnemyWaveHard();
	void SetEnemyWaveHardcore();

public:
	EnemyManager(ProjectileManager&);

	void SetAllWaves();
	void Spawn();
	void DefineEnemies(Enemy& easyEnemy, Enemy& mediumEnemy, Enemy& hardEnemy, Enemy& hardcoreEnemy);
	//Spawn enemy at random possible position
	void AddEnemy(EntityType enemyType,Vector2f startPosition);
	std::vector<Enemy>& GetAllEnemies();


};

