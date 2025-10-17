#pragma once
#include <SFML/Graphics.hpp>

#include "Animation.h"
#include "ProjectileManager.h"

class Entity : public sf::Transformable, public sf::Drawable
{
private:
	int healthPoints_;
	int damage_;
	Animation animation_;
	Vector2f textureSize_;
	float spriteScale_;

public:
	Entity(std::string spritesPath, float animSpeed, int healthPoint, int damage, float spriteScale);
	void Load(ProjectileManager* projectileManager);
	void AnimationUpdate();
	void Destroy();
	void TakeDamage();

protected:
	ProjectileManager* projectileManager_;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	Vector2f GetTextureSize();
};

