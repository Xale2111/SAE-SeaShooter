#pragma once
#include <optional>
#include <SFML/Graphics.hpp>
#include "Animation.h"

enum class ProjectileState
{
	Spawned,
	Moving,
	Destroyed
};

using namespace sf;
class Projectile : public Transformable, public Drawable
{
private:
	uint64_t id_;

	Vector2f position_;
	Animation animation_;
	float speed_;
	ProjectileState state_=ProjectileState::Spawned;

	Vector2f direction_;

	Clock clock_;


public:
	void Load(std::string spritePath, float speed = 350 );
	void SetDirection(Vector2f newDirection);
	void SetPosition(Vector2f newPosition);
	Vector2f GetPosition();
	void AnimationUpdate();
	ProjectileState Move();
	void SetID(uint64_t id);
	uint64_t GetID();
protected:
	void draw(RenderTarget& target, RenderStates states) const override;

};

