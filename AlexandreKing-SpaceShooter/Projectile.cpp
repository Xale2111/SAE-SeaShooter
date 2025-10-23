#include "Projectile.h"

#include <corecrt_math_defines.h>

void Projectile::Load(std::string spritePath, float speed)
{
	animation_.Load(spritePath, 0.05f);
	CenterOrigin();
	speed_ = speed;
}

void Projectile::SetDirection(Vector2f newDirection)
{
	direction_ = newDirection;
	//SetRotation(direction_);
}

void Projectile::SetPosition(Vector2f newPosition)
{
	position_ = newPosition;
}

void Projectile::CenterOrigin()
{
	//Set the origin based on the texture
	if (animation_.GetTexture())
	{
		Vector2f newOrigin{
			static_cast<float>(animation_.GetTexture()->getSize().x) / 2.f,
			static_cast<float>(animation_.GetTexture()->getSize().y) / 2.f
		};
		setOrigin(newOrigin);
	}
}

void Projectile::SetRotation(Vector2f direction)
{

	float angleRadians = atan2(direction.y, direction.x);
	float angleDegrees = angleRadians * 180 / M_PI;
	rotate(degrees(angleDegrees-90));
}

Vector2f Projectile::GetPosition()
{
	return position_;
}

void Projectile::AnimationUpdate()
{
	animation_.Update();
}

ObjectState Projectile::Move(Time dt)
{

	if (direction_.length() > 0 && state_ != ObjectState::Destroyed)
	{
		state_ = ObjectState::Moving;
		SetPosition(position_ + direction_.normalized() * speed_ * dt.asSeconds());
	}
	if (GetPosition().y <-100 || GetPosition().y>2020)
	{
		state_ = ObjectState::Destroyed;
	}
	return state_;

}

void Projectile::SetID(uint64_t id)
{
	id_ = id;
}

uint64_t Projectile::GetID()
{
	return id_;
}

void Projectile::draw(RenderTarget& target, RenderStates states) const
{
	sf::Texture texture = *animation_.GetTexture();
	Sprite sprite(texture);
	sprite.setOrigin({ static_cast<float>(texture.getSize().x / 2), static_cast<float>(texture.getSize().y / 2) });
	sprite.setPosition(position_);
	states.transform *= getTransform();

	target.draw(sprite, states);
}
