#include "Collider.h"

void Collider::SetPosition(Vector2f position) const
{
	hitbox_->setPosition(position);
}

void Collider::SetHitbox(sf::Shape* shape, Vector2f position)
{

	hitbox_ = shape;

	hitbox_->setFillColor(Color(255, 0, 0, 100));

	hitbox_->setPosition(position);
}

Shape& Collider::GetHitboxRef() const
{
	return *hitbox_;
}
