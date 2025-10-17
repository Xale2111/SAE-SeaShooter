#include "Projectile.h"

void Projectile::Load(std::string spritePath, float speed)
{
	animation_.Load(spritePath, 0.05f);
	speed_ = speed;
}

void Projectile::SetDirection(Vector2f newDirection)
{
	direction_ = newDirection;
}

void Projectile::SetPosition(Vector2f newPosition)
{
	position_ = newPosition;
}

Vector2f Projectile::GetPosition()
{
	return position_;
}

void Projectile::AnimationUpdate()
{
	animation_.Update();
}

ProjectileState Projectile::Move()
{
	if (state_ == ProjectileState::Spawned)
	{
		clock_.restart();
		state_ = ProjectileState::Moving;
	}
	Time deltaTime = clock_.restart();

	if (direction_.length() > 0)
	{
		SetPosition(position_ + direction_.normalized() * speed_ * deltaTime.asSeconds());
	}
	if (GetPosition().y <-500 || GetPosition().y>2500)
	{
		state_ = ProjectileState::Destroyed;
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
