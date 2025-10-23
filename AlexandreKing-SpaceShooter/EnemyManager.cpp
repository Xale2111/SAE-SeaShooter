#include "EnemyManager.h"

#include <iostream>

constexpr float winWidth = 1920;
constexpr int winHeight = 1080;

//Easy wave, this can then be combined with the other ones to create a full game with different wave complexity 
void EnemyManager::SetEnemyWaveEasy()
{
	//Define the wave
	// Segment 1
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kSingle, EnemyStartPosition::kMiddle, 1));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 1));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 1));

	// Segment 2
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kSingle, EnemyStartPosition::kMiddle, 3));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kDuo, EnemyStartPosition::kLeft, 2));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kDuo, EnemyStartPosition::kRight, 0));

	// Segment 3
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 5));

	// Segment 4
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 3));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kDuo, EnemyStartPosition::kMiddle, 0));

	// Segment 5
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kDuo, EnemyStartPosition::kMiddle, 5));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 0));

	// Segment 6
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kMiddle, 7.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 0));

	// Segment 7
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kMiddle, 7.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kLeft, 1));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kRight, 0));

	// Segment 8
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 5));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kRight, 0));

	// Segment 9
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kDuo, EnemyStartPosition::kMiddle, 5));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 0));

	// Segment 10
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kDuo, EnemyStartPosition::kMiddle, 10));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kDuo, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kDuo, EnemyStartPosition::kRight, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 10));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 0));

	// Segment 11
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardcoreEnemy, EnemyFormation::kSingle, EnemyStartPosition::kMiddle, 15));
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

Vector2f EnemyManager::GetStartPositionFromEnum(EnemyStartPosition startPosition)
{
	Vector2f startCoordinates({ 0,0 });
	switch (startPosition)
	{
	case kLeft:
		startCoordinates = possibleStartPositions[0];
		break;

	case kMiddle:
	{
		int randMiddle = rand() % 3 + 1;
		std::cout << randMiddle << std::endl;
		startCoordinates = possibleStartPositions[randMiddle];
	}
	break;

	case kRight:
		startCoordinates = possibleStartPositions[4];
		break;

	default:
		startCoordinates = possibleStartPositions[2];
		break;
	}

	return startCoordinates;
}

Vector2f EnemyManager::GetDirectionFromStartPosition(EnemyStartPosition startPosition)
{

	Vector2f direction({ 0,0 });
	switch (startPosition)
	{
	case kLeft:
		direction = Vector2f(1,1);
		break;

	case kMiddle:
		direction = Vector2f(0, 1);
		break;

	case kRight:
		direction = Vector2f(-1, 1);
		break;

	default:
		direction = Vector2f(0, 1);
		break;
	}

	return direction;
}


//PUBLIC


EnemyManager::EnemyManager(ProjectileManager& projectile_manager, AudioManager& audio_manager) : enemyID(0)
{
	easyEnemy_.Load(&projectile_manager, &audio_manager);
	mediumEnemy_.Load(&projectile_manager, &audio_manager);
	hardEnemy_.Load(&projectile_manager, &audio_manager);
	hardcoreEnemy_.Load(&projectile_manager, &audio_manager);
}

void EnemyManager::SetAllWaves()
{
	SetEnemyWaveEasy();
	SetEnemyWaveMedium();
	SetEnemyWaveHard();
	SetEnemyWaveHardcore();
}

void EnemyManager::Spawn(Time dt)
{
	//spawn the next wave segment if the defined delay is greater the current elapsed time
	if (enemyWavePrediction.size() > 0 && currentWaveIndex_ < enemyWavePrediction.size())
	{
		waveDelay += dt;
		if (waveDelay.asSeconds() >= enemyWavePrediction[currentWaveIndex_].GetDelay())
		{
			int width = winWidth;
			CreateFormation(enemyWavePrediction[currentWaveIndex_]);
			waveDelay = milliseconds(0);
			currentWaveIndex_++;
		}
		//TODO : add enemy with pattern based on formation
	}
}

void EnemyManager::CreateFormation(WaveSegment wave)
{
	switch (wave.GetFormation())
	{
	case EnemyFormation::kSingle:
		AddEnemy(wave.GetType(), wave.GetStartPosition());
		break;
	case EnemyFormation::kDuo :
		AddEnemy(wave.GetType(), wave.GetStartPosition(), { -75,0 });
		AddEnemy(wave.GetType(), wave.GetStartPosition(),{75,0});
			break;
	case EnemyFormation::kTriangle :
		//Place first normally
		//Place second and third like duo but behind the first one
		break;
	case EnemyFormation::kBigTriangle :
		break;

	default:
		std::cout << "Shouldn't pass through here... (ENEMY MANAGER->CREATE FORMATION)";
		break;

	}
}

//Final step to add an enemy. Enemy is now in the list and will be displayed in game
void EnemyManager::AddEnemy(EntityType enemyType, EnemyStartPosition startPosition, Vector2f offset)
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

	newEnemy.SetDirection(GetDirectionFromStartPosition(startPosition));
	newEnemy.SetID(enemyID);

	newEnemy.SetPosition(GetStartPositionFromEnum(startPosition)+offset);


	allEnemies_.emplace_back(newEnemy);
	enemyID++;

}

std::vector<Enemy>& EnemyManager::GetAllEnemies()
{
	return allEnemies_;
}


