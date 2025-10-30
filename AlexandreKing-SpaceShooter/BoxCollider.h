#pragma once
#include "Collider.h"

class BoxCollider : public Collider
{
private:
	RectangleShape newShape_;

public:
	void InstanciateNewBoxCollider(Vector2f size, float scale, float rotation = 0);
};

