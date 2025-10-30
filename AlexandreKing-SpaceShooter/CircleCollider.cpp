#include "CircleCollider.h"
void CircleCollider::InstanciateNewCircleCollider(float radius, Vector2f origin, float scale)
{

	newHitbox_.setRadius(radius);
	newHitbox_.setOrigin(origin);
	newHitbox_.scale(Vector2f(scale,scale));
	newHitbox_.setFillColor(Color(255, 0, 0, 100));

	hitbox_ = &newHitbox_;
}
