#include "BoxCollider.h"

void BoxCollider::InstanciateNewBoxCollider(Vector2f size, float scale, float rotation)
{
	newShape_.setSize(size);
	newShape_.setOrigin(Vector2f(size.x / 2, size.y / 2));
	newShape_.scale(Vector2f(scale, scale));
	newShape_.setFillColor(Color(255, 0, 0, 100));
	newShape_.rotate(degrees(rotation));


	hitbox_ = &newShape_;
}
