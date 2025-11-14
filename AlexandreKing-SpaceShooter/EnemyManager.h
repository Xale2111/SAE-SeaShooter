#pragma once
#include "Enemy.h"
#include "Player.h"
#include "WaveSegment.h"

class EnemyManager
{
private:
	std::vector<Enemy> allEnemies_;
	std::vector<Enemy> removeEnemies_;

	//first pair = enemy difficulty and formation, float is the delay between two enemy spawning
	std::vector<WaveSegment> enemyWavePrediction;

	//Create template of enemy (green-> easy, blue-> medium, red-> hard, Yellow-> HARDCORE)
	Enemy easyEnemy_ = Enemy(50, 10, 0.4f, EntityType::kEasyEnemy, 1, 1, 50, { 0,0 }, 100, -1);
	Enemy mediumEnemy_ = Enemy(220, 25, 1, EntityType::kMediumEnemy, 0.6, 1, 100, { 0,0 }, 110, -1);
	Enemy hardEnemy_ = Enemy(500, 35, 0.35f, EntityType::kHardEnemy, 0.8, 3, 250, { 0,0 }, 125, -1);
	Enemy hardcoreEnemy_ = Enemy(1500, 50, 1, EntityType::kHardcoreEnemy, 0.45, 5, 750, { 0,0 }, 80, -1);

	uint64_t enemyID;

	int currentWaveIndex_ = 0;
	bool canContinueToNextWave_ = true;
	bool startingNewRound_ = false;

	Time waveDelay;

	Vector2f possibleStartPositions[5] = {
	{ -100.f,  -100.f },  // kLeft
	{  430.f,  -100.f },  // kMiddleLeft
	{  960.f,  -100.f },  // kMiddle 
	{ 1490.f,  -100.f },  // kMiddleRight
	{ 2020.f,  -100.f }   // kRight
	};

	void SetEnemyWaveEasy();
	void SetEnemyWaveMedium();
	void SetEnemyWaveHard();
	void SetEnemyWaveHardcore();

	Vector2f GetStartPositionFromEnum(EnemyStartPosition startPosition, int forceMiddleSpawnPosition = -1);
	Vector2f GetDirectionFromStartPosition(EnemyStartPosition startPosition);

public:
	EnemyManager(ProjectileManager& projectile_manager, AudioManager& audio_manager);

	void SetAllWaves();
	void Spawn(Time deltaTime);
	//Spawn enemy at random possible position
	void CreateFormation(WaveSegment segment);
	void AddEnemy(EntityType enemyType, EnemyStartPosition startPosition, Vector2f offset = { 0,0 }, int middleSpawnPosition = -1);

	void AddEnemyToRemove(Enemy& enemyToRemove);
	void RemoveEnemies();

	std::vector<Enemy>& GetAllEnemies();

	bool IsStartingNewRound();

	void Reset();


};

