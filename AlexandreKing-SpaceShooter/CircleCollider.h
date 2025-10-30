#pragma once
#include "Collider.h"

class CircleCollider : public Collider
{
private:
	CircleShape newHitbox_;

public:
	void InstanciateNewCircleCollider(float radius, Vector2f origin, float scale);
};

