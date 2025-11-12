#include "WaveSegment.h"

WaveSegment::WaveSegment(EntityType type, EnemyFormation formation, EnemyStartPosition strPosition, float delay,bool lastSegment)
{
	type_ = type;
	formation_ = formation;
	startPosition_ = strPosition;
	delay_ = delay;
	isLastOfSegmentOfTheWave = lastSegment;
}

EntityType WaveSegment::GetType()
{
	return type_;
}

EnemyFormation WaveSegment::GetFormation()
{
	return formation_;
}

EnemyStartPosition WaveSegment::GetStartPosition()
{
	return startPosition_;
}

float WaveSegment::GetDelay()
{
	return delay_;
}

bool WaveSegment::IsLastSegment()
{
	return isLastOfSegmentOfTheWave;
}
