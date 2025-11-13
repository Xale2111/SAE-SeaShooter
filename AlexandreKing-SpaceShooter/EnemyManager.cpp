#include "EnemyManager.h"

#include <iostream>

constexpr float winWidth = 1920;
constexpr int winMenuHeight = 1080;

//Easy wave, this can then be combined with the other ones to create a full game with different wave complexity 
void EnemyManager::SetEnemyWaveEasy()
{
	//Define the wave
	// Segment 1
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kSingle, EnemyStartPosition::kMiddle, 1.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 1.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 1.f));

	// Segment 2
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kSingle, EnemyStartPosition::kMiddle, 8.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kDuo, EnemyStartPosition::kLeft, 2.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kDuo, EnemyStartPosition::kRight, 0));

	// Segment 3
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 7.5f));

	// Segment 4
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 6.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kDuo, EnemyStartPosition::kMiddle, 0));

	// Segment 5
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kDuo, EnemyStartPosition::kMiddle, 5.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 0));

	// Segment 6
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kMiddle, 7.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 0));

	// Segment 7
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kMiddle, 7.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kLeft, 1.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kRight, 0));

	// Segment 8
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 10.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kRight, 0));

	// Segment 9
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kDuo, EnemyStartPosition::kMiddle, 10.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 0));

	// Segment 10
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kDuo, EnemyStartPosition::kMiddle, 15.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kDuo, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kDuo, EnemyStartPosition::kRight, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 10.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 0));

	// Segment 11
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardcoreEnemy, EnemyFormation::kSingle, EnemyStartPosition::kMiddle, 15.f,true));
}

void EnemyManager::SetEnemyWaveMedium()
{
	//Segment 1
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 5.f));

	//Segment 2
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kDuo, EnemyStartPosition::kMiddle, 5.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kDuo, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kDuo, EnemyStartPosition::kRight, 0));

	//Segment 3
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kMiddle, 10.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kRight, 0));

	//Segment 4
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 15.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kRight, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 1.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kRight, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 1.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kRight, 0));

	//Segment 5
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 15.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kRight, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 1.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kRight, 0));

	//Segment 6
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardcoreEnemy, EnemyFormation::kSingle, EnemyStartPosition::kMiddle, 10.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 1.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 1.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kMiddle, 1.f));

	//Segment 7
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 12.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kRight, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kMiddle, 1.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kDuo, EnemyStartPosition::kLeft, 0));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kDuo, EnemyStartPosition::kRight, 0));

	//Segment 8
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kMiddle, 12.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kMiddle, 0.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kMiddle, 0.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kMiddle, 0.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kMiddle, 0.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kMiddle, 0.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kMiddle, 0.5f));

	//Segment 9
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 15.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 0.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kEasyEnemy, EnemyFormation::kBigTriangle, EnemyStartPosition::kMiddle, 0.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardcoreEnemy, EnemyFormation::kDuo, EnemyStartPosition::kMiddle, 0.5f));

	//Segment 10
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kMiddle, 15.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 0.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 0.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kMiddle, 0.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 0.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 0.5f));

	//Segment 11
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kMiddle, 12.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kLeft, 0.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kMediumEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kRight, 0.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kDuo, EnemyStartPosition::kMiddle, 0.5f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kDuo, EnemyStartPosition::kLeft, 0.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kDuo, EnemyStartPosition::kRight, 0.f));

	//Segment 12
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardcoreEnemy, EnemyFormation::kTriangle, EnemyStartPosition::kMiddle, 25.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kLeft, 0.f));
	enemyWavePrediction.emplace_back(WaveSegment(EntityType::kHardEnemy, EnemyFormation::kSingle, EnemyStartPosition::kRight, 0.f, true));
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

Vector2f EnemyManager::GetStartPositionFromEnum(EnemyStartPosition startPosition, int forceMiddleSpawnPosition)
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
		if (forceMiddleSpawnPosition >=0 && forceMiddleSpawnPosition < possibleStartPositions->length())
		{
			randMiddle = forceMiddleSpawnPosition;
		}
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
	easyEnemy_.DefineAnimation(0.2f, TextureManager::ID::kEasyEnemy);
	mediumEnemy_.Load(&projectile_manager, &audio_manager);
	mediumEnemy_.DefineAnimation(0.2f, TextureManager::ID::kMediumEnemy);
	hardEnemy_.Load(&projectile_manager, &audio_manager);
	hardEnemy_.DefineAnimation(0.15f, TextureManager::ID::kHardEnemy);
	hardcoreEnemy_.Load(&projectile_manager, &audio_manager);
	hardcoreEnemy_.DefineAnimation(0.2f, TextureManager::ID::kHardcoreEnemy);
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
		if (canContinueToNextWave)
		{
			waveDelay += dt;
			if (waveDelay.asSeconds() >= enemyWavePrediction[currentWaveIndex_].GetDelay())
			{
				CreateFormation(enemyWavePrediction[currentWaveIndex_]);
				waveDelay = milliseconds(0);
				if (enemyWavePrediction[currentWaveIndex_].IsLastSegment())
				{
					//While last enemy isn't dead, don't continue
					canContinueToNextWave = false;
				}
				else
				{
					currentWaveIndex_++;
				}
			}
		}
		else
		{
			if (allEnemies_.size() <= 0)
			{
				canContinueToNextWave = true;
				currentWaveIndex_++;
			}
		}
	}
	if (currentWaveIndex_ >= enemyWavePrediction.size())
	{
		currentWaveIndex_ = 0;
		//TODO (OPTIONNAL): Upgrade enemies when restarting. (set max health of each enemy to 125% of current maxHealth)  
	}
}

void EnemyManager::CreateFormation(WaveSegment wave)
{
	int middleSpawnPosition = rand() % 3 + 1;
	
	switch (wave.GetFormation())
	{
	case EnemyFormation::kSingle:
		AddEnemy(wave.GetType(), wave.GetStartPosition());
		break;
	case EnemyFormation::kDuo :
		AddEnemy(wave.GetType(), wave.GetStartPosition(), { -75,0 },middleSpawnPosition);
		AddEnemy(wave.GetType(), wave.GetStartPosition(),{75,0}, middleSpawnPosition);
		break;
	case EnemyFormation::kTriangle :
		AddEnemy(wave.GetType(), wave.GetStartPosition(),{0,0}, middleSpawnPosition);
		AddEnemy(wave.GetType(), wave.GetStartPosition(), { 75,-100 }, middleSpawnPosition);
		AddEnemy(wave.GetType(), wave.GetStartPosition(), { -75,-100 }, middleSpawnPosition);
		break;
	case EnemyFormation::kBigTriangle :
		AddEnemy(wave.GetType(), wave.GetStartPosition(),{0,0}, middleSpawnPosition);
		AddEnemy(wave.GetType(), wave.GetStartPosition(), { -75,-100 }, middleSpawnPosition);
		AddEnemy(wave.GetType(), wave.GetStartPosition(), { 75,-100 }, middleSpawnPosition);
		AddEnemy(wave.GetType(), wave.GetStartPosition(), { -150,-200 }, middleSpawnPosition);
		AddEnemy(wave.GetType(), wave.GetStartPosition(), { 150,-200 }, middleSpawnPosition);
		break;

	default:
		std::cout << "Shouldn't pass through here... (ENEMY MANAGER->CREATE FORMATION)";
		break;
	}
}

//Final step to add an enemy. Enemy is now in the list and will be displayed in game
void EnemyManager::AddEnemy(EntityType enemyType, EnemyStartPosition startPosition, Vector2f offset, int middleSpawnPosition)
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

	newEnemy.SetPosition(GetStartPositionFromEnum(startPosition, middleSpawnPosition)+offset);

	allEnemies_.emplace_back(newEnemy);
	allEnemies_.back().SetCollider(newEnemy.getRotation().asDegrees());
	enemyID++;

}

void EnemyManager::AddEnemyToRemove(Enemy& enemyToRemove)
{
	removeEnemies_.push_back(enemyToRemove);
}

void EnemyManager::RemoveEnemies()
{
	allEnemies_.erase(std::remove_if(allEnemies_.begin(), allEnemies_.end(),
		[&](Enemy& p) {
			return std::any_of(removeEnemies_.begin(), removeEnemies_.end(), [&](Enemy& r) {
				return p.GetID() == r.GetID();
				});
		}),
		allEnemies_.end());
}

std::vector<Enemy>& EnemyManager::GetAllEnemies()
{
	return allEnemies_;
}

void EnemyManager::Reset()
{
	allEnemies_.clear(); 
	removeEnemies_.clear();
	enemyID = 0 ;
	currentWaveIndex_ = 0;
}


