#pragma once
#include <SFML/Graphics.hpp>

#include "Animation.h"
#include "ObjectState.h"

using namespace sf;

class Meteor : public Drawable, public Transformable
{
private:
	uint64_t id_;


	Vector2f direction_;
	float rotationDegree_;
	float currentRotation_;
	float speed_;
	Animation animation_;
	ObjectState state_ = ObjectState::None;
	Vector2f position_;
	Vector2f scale_;

public:
	void Load(std::string spritePath);
	void SetDirection(Vector2f newDirection);
	void SetRotationDegrees(float rtDegrees);
	void IncreaseRotation();
	void SetSpeed(float newSpeed);
	void SetPosition(Vector2f newPosition);
	void SetMeteorSize(float newScale);
	void AnimationUpdate();
	ObjectState Move(Time deltaTime);
	void SetId(uint64_t ID);
	uint64_t GetId();


protected:
	void draw(RenderTarget& target, RenderStates states) const override;

};

