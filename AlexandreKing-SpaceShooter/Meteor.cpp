#include "Meteor.h"

#include <iostream>


void Meteor::Load(std::string spritePath)
{
	animation_.Load(spritePath,1);
	setOrigin({ static_cast<float>(animation_.GetTexture()->getSize().x / 2), static_cast<float>(animation_.GetTexture()->getSize().y / 2) });
	layer_ = ObjectLayer::kMeteor;
}

void Meteor::SetDirection(Vector2f newDirection)
{
	direction_ = newDirection;
}

void Meteor::SetRotationDegrees(float rtDegrees)
{
	rotationDegree_ = rtDegrees;
}

void Meteor::IncreaseRotation()
{
	currentRotation_ += rotationDegree_;
}

void Meteor::SetSpeed(float newSpeed)
{
	speed_ = newSpeed;
}

void Meteor::SetPosition(Vector2f newPosition)
{
	position_ = newPosition;
}

void Meteor::SetMeteorSize(float newScale)
{
	scale_ = { newScale,newScale };
}

void Meteor::AnimationUpdate()
{
	animation_.Update();
}

ObjectState Meteor::Move(Time deltaTime)
{
	if (direction_.length() > 0 && state_ != ObjectState::kDestroyed)
	{
		state_ = ObjectState::kMoving;
		position_ += direction_.normalized() * speed_ * deltaTime.asSeconds();
	}

	if (position_.y>2020)
	{
		state_ = ObjectState::kDestroyed;
	}

	return state_;
}

void Meteor::SetId(uint64_t ID)
{
	id_ = ID;
}

uint64_t Meteor::GetId()
{
	return id_;
}

void Meteor::SetCollider(ColliderType colliderType, float scale)
{
	if (colliderType == ColliderType::kCircle)
	{
		float radius = 130 * scale;
		Vector2f origin = Vector2f(getPosition().x+radius, (getPosition().y + radius));

		CircleCollider* newCollider = new CircleCollider();
		newCollider->InstanciateNewCircleCollider(radius, origin, 0.9f);
		hitbox_ = *newCollider;
	}
	else if (colliderType == ColliderType::kBox)
	{
		Vector2f hitboxSize = Vector2f(animation_.GetTexture()->getSize().x, animation_.GetTexture()->getSize().y) * scale;

		BoxCollider* newCollider = new BoxCollider();
		newCollider->InstanciateNewBoxCollider(hitboxSize, 0.9f, getRotation().asDegrees());
		hitbox_ = *newCollider;
	}
}

Collider Meteor::GetHitbox()
{
	return hitbox_;
}

ObjectLayer Meteor::GetLayer()
{
	return layer_;
}

void Meteor::Destroy()
{
	state_ = ObjectState::kDestroyed;
}

void Meteor::draw(RenderTarget& target, RenderStates states) const
{
	Texture texture = *animation_.GetTexture();
	Sprite sprite(texture);
	sprite.setOrigin({ static_cast<float>(texture.getSize().x / 2), static_cast<float>(texture.getSize().y / 2) });
	sprite.setPosition(position_);
	sprite.setRotation(degrees(currentRotation_));
	sprite.setScale(scale_);

	hitbox_.SetPosition(sprite.getPosition());
	hitbox_.GetHitboxRef().rotate(degrees(rotationDegree_));
	
	target.draw(sprite, states);
}
