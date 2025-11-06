#include "Entity.h"


//Protected
void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Texture texture = animation_->GetTexture();
	sf::Sprite sprite(texture);
	sprite.setOrigin({ static_cast<float>(texture.getSize().x / 2), static_cast<float>(texture.getSize().y / 2) });
	sprite.setScale({ spriteScale_,spriteScale_ });

	states.transform *= getTransform();
	collider_.SetPosition(getPosition());

	target.draw(sprite, states);
}

Vector2f Entity::GetTextureSize()
{
	return textureSize_ * spriteScale_;
}

void Entity::SetAnimation(Animation& newAnimation, int textureIndex)
{
	animation_ = &newAnimation;
	animation_->SetIndex(textureIndex);
}

int Entity::GetAnimationIndex()
{
	return  animation_->GetIndex();
}


const Texture& Entity::GetAnimationTexture() const
{
	return animation_->GetTexture();
}

//Public
Entity::Entity(int healthPoint, int damage, float spriteScale, EntityType type)
{
	healthPoints_ = healthPoint;
	damage_ = damage;
	textureSize_ = {0,0};
	spriteScale_ = spriteScale;
	type_ = type;
}

void Entity::Load(ProjectileManager* projectileManager, AudioManager* audioManager)
{
	projectileManager_ = projectileManager;
	audioManager_ = audioManager;
}

void Entity::AnimationUpdate()
{
	animation_->Update();
	textureSize_ = Vector2f(animation_->GetTexture().getSize().x, animation_->GetTexture().getSize().y);
}

void Entity::TakeDamage(int damage)
{
	healthPoints_ -= damage;
}

int Entity::GetHealthPoints()
{
	return healthPoints_;
}
