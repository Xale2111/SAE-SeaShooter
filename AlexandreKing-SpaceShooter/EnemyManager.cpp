#include "EnemyManager.h"

constexpr float winWidth = 1920;
constexpr int winHeight = 1080;

//Easy wave, this can then be combined with the other ones to create a full game with different wave complexity 
void EnemyManager::SetEnemyWaveEasy()
{
	//Define the wave
	//segment 1
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ easyEnemy_, EnemyFormation::kSingleMiddle }, 1));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ easyEnemy_, EnemyFormation::kSingleLeft }, 1));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ easyEnemy_, EnemyFormation::kSingleRight }, 1));

	//segment 2
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ mediumEnemy_, EnemyFormation::kSingleMiddle }, 3));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ easyEnemy_, EnemyFormation::kDuoLeft }, 2));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ easyEnemy_, EnemyFormation::kDuoLeft }, 0));

	//segment 3
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ easyEnemy_, EnemyFormation::kBigTriangleMiddle }, 5));

	//segment 4
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ mediumEnemy_, EnemyFormation::kSingleLeft }, 3));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ mediumEnemy_, EnemyFormation::kSingleRight }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ easyEnemy_, EnemyFormation::kDuoMiddle },0));

	//segment 5
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ mediumEnemy_, EnemyFormation::kDuoMiddle }, 5));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ mediumEnemy_, EnemyFormation::kSingleLeft }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ mediumEnemy_, EnemyFormation::kSingleRight }, 0));

	//segment 6
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ hardEnemy_, EnemyFormation::kSingleMiddle }, 7.5f));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ easyEnemy_, EnemyFormation::kSingleRight }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ easyEnemy_, EnemyFormation::kSingleLeft }, 0));

	//segment 7

	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ mediumEnemy_, EnemyFormation::kTriangleMiddle }, 7.5f));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ easyEnemy_, EnemyFormation::kTriangleLeft }, 1));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ easyEnemy_, EnemyFormation::kTriangleRight }, 0));

	//segment 8
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ easyEnemy_, EnemyFormation::kBigTriangleMiddle }, 5));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ easyEnemy_, EnemyFormation::kBigTriangleLeft }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ easyEnemy_, EnemyFormation::kBigTriangleRight }, 0));

	//segment 9
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ hardEnemy_, EnemyFormation::kDuoMiddle }, 5));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ mediumEnemy_, EnemyFormation::kSingleRight }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ mediumEnemy_, EnemyFormation::kSingleLeft }, 0));

	//segment 10
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ mediumEnemy_, EnemyFormation::kDuoMiddle }, 10));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ mediumEnemy_, EnemyFormation::kDuoLeft }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ mediumEnemy_, EnemyFormation::kDuoRight }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ mediumEnemy_, EnemyFormation::kBigTriangleMiddle }, 10));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ hardEnemy_, EnemyFormation::kSingleLeft }, 0));
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ hardEnemy_, EnemyFormation::kSingleRight }, 0));

	//segment 11
	enemyWavePrediction.emplace_back(std::pair<std::pair<Enemy*, EnemyFormation>, float>({ hardcoreEnemy_, EnemyFormation::kSingleMiddle }, 15));

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
			AddEnemy(currentWave.first, { (float)(rand() % width),0 });

			waveDelay = milliseconds(0);
			currentWaveIndex_++;

		}
		//TODO : add enemy with pattern based on formation
		
	}
}

void EnemyManager::DefineEnemies(Enemy* easyEnemy, Enemy* mediumEnemy, Enemy* hardEnemy, Enemy* hardcoreEnemy)
{
	easyEnemy_ = easyEnemy;
	mediumEnemy_ = mediumEnemy;
	hardEnemy_ = hardEnemy;
	hardcoreEnemy_ = hardcoreEnemy;
}

//Final step to add an enemy. Enemy is now in the list and will be displayed in game
void EnemyManager::AddEnemy(Enemy* enemy,Vector2f startPosition)
{
	Enemy newEnemy = *enemy;
	newEnemy.SetDirection({ 0,1 });
	newEnemy.SetPosition(startPosition);	

	allEnemies_.emplace_back(newEnemy);

}

std::vector<Enemy>& EnemyManager::GetAllEnemies()
{
	return allEnemies_;
}


