#include "Entity.h"


//Protected
void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Texture texture = *animation_.GetTexture();
	sf::Sprite sprite(texture);
	sprite.setOrigin({ static_cast<float>(texture.getSize().x / 2), static_cast<float>(texture.getSize().y / 2) });
	sprite.setScale({ spriteScale_,spriteScale_ });

	states.transform *= getTransform();
	hitbox_->setPosition(getPosition());

	target.draw(sprite, states);
	target.draw(*hitbox_);
}

Vector2f Entity::GetTextureSize()
{
	return textureSize_ * spriteScale_;
}

void Entity::SetHitbox(sf::Shape* shape, float scale)
{
	hitbox_ = shape;

	hitbox_->setFillColor(Color(255,0,0,100));

	hitbox_->scale(Vector2f(scale,scale));

	hitbox_->setPosition(getPosition());
}

//Public
Entity::Entity(std::string spritesPath, float animSpeed, int healthPoint, int damage, float spriteScale, EntityType type)
{
	healthPoints_ = healthPoint;
	damage_ = damage;
	animation_.Load(spritesPath, animSpeed);
	textureSize_ = {0,0};
	spriteScale_ = spriteScale;
	type_ = type;
}

void Entity::Load(ProjectileManager* projectileManager, AudioManager* audioManager)
{
	projectileManager_ = projectileManager;
	audioManager_ = audioManager;
	SetHitboxSize();
}

void Entity::AnimationUpdate()
{
	animation_.Update();
	textureSize_ = Vector2f(animation_.GetTexture()->getSize().x, animation_.GetTexture()->getSize().y);
}
