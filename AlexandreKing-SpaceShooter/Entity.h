#pragma once

#include <numbers>

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "AudioManager.h"
#include "Collider.h"

#include "ProjectileManager.h"

#include "EntityType.h"
#include "ObjectLayer.h"


constexpr float angle1 = 12.5;
constexpr float angleR1 = (90 + angle1) * std::numbers::pi / 180.f;
constexpr float angleL1 = (90 - angle1) * std::numbers::pi / 180.f;

constexpr float angle2 = 25.f;
constexpr float angleR2 = (90 + angle2) * std::numbers::pi / 180.f;
constexpr float angleL2 = (90 - angle2) * std::numbers::pi / 180.f;

class Entity : public sf::Transformable, public sf::Drawable
{
private:
	int healthPoints_;
	sf::Vector2f textureSize_;

	Animation* animation_;


protected:

	Vector2f leftDir1 = { cos(angleL1) ,-sin(angleL1) };
	Vector2f rightDir1 = { cos(angleR1) ,-sin(angleR1) };

	Vector2f leftDir2 = { cos(angleL2) ,-sin(angleL2) };
	Vector2f rightDir2 = { cos(angleR2) ,-sin(angleR2) };

	int damage_;
	EntityType type_;
	float spriteScale_;

	ObjectLayer layer_;

	Collider collider_;

	ProjectileManager* projectileManager_;
	AudioManager* audioManager_;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Vector2f GetTextureSize();
	virtual void SetCollider(float rotation = 0) = 0;
	void SetAnimation(Animation& newAnimation, int textureIndex);
	int GetAnimationIndex();
	const Texture& GetAnimationTexture() const;


public:
	Entity(int healthPoint, int damage, float spriteScale, EntityType type);
	void Load(ProjectileManager* projectileManager, AudioManager* audioManager);
	void AnimationUpdate();
	void TakeDamage(int damage);
	int GetHealthPoints();
	virtual void DetectCollision() = 0;
};

