#include "EnemyManager.h"

#include <iostream>

constexpr float winWidth = 1920;
constexpr int winHeight = 1080;

//Easy wave, this can then be combined with the other ones to create a full game with different wave complexity 
void EnemyManager::SetEnemyWaveEasy()
{
	//Define the wave
	//segment 1
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kEasyEnemy, EnemyFormation::kSingleMiddle }, 1));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kEasyEnemy, EnemyFormation::kSingleLeft }, 1));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kEasyEnemy, EnemyFormation::kSingleRight }, 1));

	//segment 2
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kMediumEnemy, EnemyFormation::kSingleMiddle }, 3));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kEasyEnemy, EnemyFormation::kDuoLeft }, 2));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kEasyEnemy, EnemyFormation::kDuoLeft }, 0));

	//segment 3
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kEasyEnemy, EnemyFormation::kBigTriangleMiddle }, 5));

	//segment 4
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kMediumEnemy, EnemyFormation::kSingleLeft }, 3));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kMediumEnemy, EnemyFormation::kSingleRight }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kEasyEnemy, EnemyFormation::kDuoMiddle },0));

	//segment 5
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kMediumEnemy, EnemyFormation::kDuoMiddle }, 5));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kMediumEnemy, EnemyFormation::kSingleLeft }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kMediumEnemy, EnemyFormation::kSingleRight }, 0));

	//segment 6
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kHardEnemy, EnemyFormation::kSingleMiddle }, 7.5f));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kEasyEnemy, EnemyFormation::kSingleRight }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kEasyEnemy, EnemyFormation::kSingleLeft }, 0));

	//segment 7

	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kMediumEnemy, EnemyFormation::kTriangleMiddle }, 7.5f));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kEasyEnemy, EnemyFormation::kTriangleLeft }, 1));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kEasyEnemy, EnemyFormation::kTriangleRight }, 0));

	//segment 8
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kEasyEnemy, EnemyFormation::kBigTriangleMiddle }, 5));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kEasyEnemy, EnemyFormation::kBigTriangleLeft }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kEasyEnemy, EnemyFormation::kBigTriangleRight }, 0));

	//segment 9
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kHardEnemy, EnemyFormation::kDuoMiddle }, 5));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kMediumEnemy, EnemyFormation::kSingleRight }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kMediumEnemy, EnemyFormation::kSingleLeft }, 0));

	//segment 10
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kMediumEnemy, EnemyFormation::kDuoMiddle }, 10));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kMediumEnemy, EnemyFormation::kDuoLeft }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kMediumEnemy, EnemyFormation::kDuoRight }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kMediumEnemy, EnemyFormation::kBigTriangleMiddle }, 10));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kHardEnemy, EnemyFormation::kSingleLeft }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kHardEnemy, EnemyFormation::kSingleRight }, 0));

	//segment 11
	enemyWavePrediction.emplace_back(std::pair<std::pair<EntityType, EnemyFormation>, float>({ EntityType::kHardcoreEnemy, EnemyFormation::kSingleMiddle }, 15));
	
}

void EnemyManager::SetEnemyWaveMedium()
{
	//TODO: Define medium wave
}

void EnemyManager::SetEnemyWaveHard()
{
	//TODO: Define hard wave
}

//PRIVATE
void EnemyManager::SetEnemyWaveHardcore()
{
	//TODO: Define hardcore wave
}

EnemyManager::EnemyManager(ProjectileManager& projectile_manager) : enemyID(0)
{
	easyEnemy_.Load(&projectile_manager);
	mediumEnemy_.Load(&projectile_manager);
	hardEnemy_.Load(&projectile_manager);
	hardcoreEnemy_.Load(&projectile_manager);
}


//PUBLIC

void EnemyManager::SetAllWaves()
{
	SetEnemyWaveEasy();
	SetEnemyWaveMedium();
	SetEnemyWaveHard();
	SetEnemyWaveHardcore();

}

void EnemyManager::Spawn()
{
	//spawn the next wave segment if the defined delay is greater the current elapsed time
	if (enemyWavePrediction.size() > 0)
	{
		waveDelay += clock_.restart();
		if (waveDelay.asSeconds() >= enemyWavePrediction[currentWaveIndex_].second)
		{
			auto currentWave = enemyWavePrediction[currentWaveIndex_].first;
			int width = winWidth;
			AddEnemy(currentWave.first, { (float)(rand() % width),-100 });

			waveDelay = milliseconds(0);
			currentWaveIndex_++;

		}
		//TODO : add enemy with pattern based on formation
		
	}
}

//void EnemyManager::DefineEnemies(Enemy& easyEnemy, Enemy& mediumEnemy, Enemy& hardEnemy, Enemy& hardcoreEnemy)
//{
//	easyEnemy_ = &easyEnemy;
//	mediumEnemy_ = &mediumEnemy;
//	hardEnemy_ = &hardEnemy;
//	hardcoreEnemy_ = &hardcoreEnemy;
//}

//Final step to add an enemy. Enemy is now in the list and will be displayed in game
void EnemyManager::AddEnemy(EntityType enemyType, Vector2f startPosition)
{
	Enemy newEnemy = easyEnemy_;


	switch (enemyType)
	{
	case EntityType::kEasyEnemy:
		newEnemy = easyEnemy_;
		break;
	case EntityType::kMediumEnemy:
		newEnemy = mediumEnemy_;
		break;
	case EntityType::kHardEnemy:
		newEnemy = hardEnemy_;
		break;
	case EntityType::kHardcoreEnemy:
		newEnemy = hardcoreEnemy_;
		break;
	default:
		newEnemy = easyEnemy_;
		break;
	}

	newEnemy.SetDirection({ 0,1 });
	newEnemy.SetID(enemyID);
	newEnemy.SetPosition(startPosition);


	allEnemies_.emplace_back(newEnemy);
	enemyID++;

}

std::vector<Enemy>& EnemyManager::GetAllEnemies()
{
	return allEnemies_;
}


