#include "Entity.h"

Entity::Entity(std::string spritesPath, float animSpeed, int healthPoint, int damage, float spriteScale)
{
	healthPoints_ = healthPoint;
	damage_ = damage;
	animation_.Load(spritesPath, animSpeed);
	textureSize_ = {0,0};
	spriteScale_ = spriteScale;
}

void Entity::Load(ProjectileManager* projectileManager)
{
	projectileManager_ = projectileManager;
}

void Entity::AnimationUpdate()
{
	animation_.Update();
	textureSize_ = Vector2f(animation_.GetTexture()->getSize().x, animation_.GetTexture()->getSize().y);
}


void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Texture texture = *animation_.GetTexture();
	sf::Sprite sprite(texture);
	sprite.setOrigin({static_cast<float>(texture.getSize().x/2), static_cast<float>(texture.getSize().y / 2)});
	sprite.setScale({ spriteScale_,spriteScale_ });

	states.transform *= getTransform();

	target.draw(sprite, states);
}

Vector2f Entity::GetTextureSize()
{
	return textureSize_*spriteScale_;
}

