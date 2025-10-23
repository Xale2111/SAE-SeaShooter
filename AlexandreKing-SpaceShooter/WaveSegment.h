#pragma once
#include "EntityType.h"
enum class EnemyFormation
{
	kSingle,		//1 unit 
	kDuo,			//2 units
	kTriangle,		//3 units
	kBigTriangle,	//5 units 
};

enum EnemyStartPosition
{
	kLeft,
	kMiddle,
	kRight
};

class WaveSegment
{
private:
	EntityType type_;
	EnemyFormation formation_;
	EnemyStartPosition startPosition_;
	float delay_;
public:
	WaveSegment(EntityType type, EnemyFormation formation, EnemyStartPosition strPosition, float delay);

	EntityType GetType();
	EnemyFormation GetFormation();
	EnemyStartPosition GetStartPosition();
	float GetDelay();

};

