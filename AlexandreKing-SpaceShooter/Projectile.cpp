#include "Projectile.h"
#include <corecrt_math_defines.h>

void Projectile::Load(std::string spritePath, ObjectLayer layer,float speed)
{
	animation_.Load(spritePath, 0.05f);
	CenterOrigin();
	speed_ = speed;
	layer_ = layer;
}

void Projectile::SetDirection(Vector2f newDirection)
{
	if (newDirection.length() != 0)
	{
		direction_ = newDirection.normalized();
	}
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

void Projectile::SetRotation(bool isPlayerProjectile)
{
	float angleRadians;
	isPlayerProjectile ? angleRadians = atan2(abs(direction_.y), -direction_.x) :angleRadians= atan2(abs(direction_.y), direction_.x);
	float angleDegrees = angleRadians * 180 / M_PI;
	rotation_ = degrees(angleDegrees-90);
}

void Projectile::SetCollider()
{
	BoxCollider* newHitbox = new BoxCollider;
	newHitbox->InstanciateNewBoxCollider(Vector2f(animation_.GetTexture()->getSize().x, animation_.GetTexture()->getSize().y),1.f, rotation_.asDegrees());
	hitbox_ = *newHitbox;
}

void Projectile::SetDamage(int damage)
{
	projectileDamage_ = damage;
}

int Projectile::GetDamage()
{
	return projectileDamage_;
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

	if (state_ != ObjectState::kDestroyed)
	{
		state_ = ObjectState::kMoving;
		SetPosition(position_ + direction_ * speed_ * dt.asSeconds());
	}
	if (GetPosition().y <-500 || GetPosition().y>2020)
	{
		Destroy();
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

ObjectLayer Projectile::GetLayer()
{
	return layer_;
}

Collider Projectile::GetHitbox()
{
	return hitbox_;
}

void Projectile::Destroy()
{
	state_ = ObjectState::kDestroyed;
}

void Projectile::draw(RenderTarget& target, RenderStates states) const
{
	Texture texture = *animation_.GetTexture();
	Sprite sprite(texture);
	sprite.setOrigin({ static_cast<float>(texture.getSize().x / 2), static_cast<float>(texture.getSize().y / 2) });
	sprite.setPosition(position_);
	sprite.setRotation(rotation_);

	hitbox_.SetPosition(position_);

	target.draw(sprite, states);
}
