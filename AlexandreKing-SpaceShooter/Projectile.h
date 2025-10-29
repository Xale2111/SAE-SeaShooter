#pragma once
#include <optional>
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "ObjectState.h"




using namespace sf;
class Projectile : public Transformable, public Drawable
{
private:
	uint64_t id_;

	Vector2f position_;
	Animation animation_;
	float speed_;
	ObjectState state_=ObjectState::None;

	Vector2f direction_;
	Angle rotation_;

public:
	void Load(std::string spritePath, float speed = 350 );
	void SetDirection(Vector2f newDirection);
	void SetPosition(Vector2f newPosition);
	void CenterOrigin();
	void SetRotation(bool isPlayerProjectile);
	Vector2f GetPosition();
	void AnimationUpdate();
	ObjectState Move(Time deltaTime);
	void SetID(uint64_t id);
	uint64_t GetID();
protected:
	void draw(RenderTarget& target, RenderStates states) const override;

};

