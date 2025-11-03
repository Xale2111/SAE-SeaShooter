#pragma once
#include <optional>
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "BoxCollider.h"
#include "ObjectState.h"

#include "ObjectLayer.h"



using namespace sf;
class Projectile : public Transformable, public Drawable
{
private:
	uint64_t id_;

	int projectileDamage_;

	Vector2f position_;
	Animation animation_;
	float speed_;
	ObjectState state_=ObjectState::kNone;

	Vector2f direction_;
	Angle rotation_;

	Collider hitbox_;

	ObjectLayer layer_;

protected:
	void draw(RenderTarget& target, RenderStates states) const override;

public:
	void Load(std::string spritePath, ObjectLayer layer, float speed = 350);
	void SetDirection(Vector2f newDirection);
	void SetPosition(Vector2f newPosition);
	void CenterOrigin();
	void SetRotation(bool isPlayerProjectile);
	void SetCollider();
	void SetDamage(int damage);
	int GetDamage();
	Vector2f GetPosition();

	void AnimationUpdate();
	ObjectState Move(Time deltaTime);

	void SetID(uint64_t id);
	uint64_t GetID();

	ObjectLayer GetLayer();

	Collider GetHitbox();

	void Destroy();
};

