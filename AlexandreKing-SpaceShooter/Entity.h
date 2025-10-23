#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "AudioManager.h"

#include "ProjectileManager.h"

#include "EntityType.h"

class Entity : public sf::Transformable, public sf::Drawable
{
private:
	int healthPoints_;
	int damage_;
	Animation animation_;
	sf::Vector2f textureSize_;
	float spriteScale_;

public:
	Entity(std::string spritesPath, float animSpeed, int healthPoint, int damage, float spriteScale, EntityType type);
	void Load(ProjectileManager* projectileManager, AudioManager* audioManager);
	void AnimationUpdate();
	void Destroy();
	void TakeDamage();

protected:
	EntityType type_;

	ProjectileManager* projectileManager_;
	AudioManager* audioManager_;


	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Vector2f GetTextureSize();
};

