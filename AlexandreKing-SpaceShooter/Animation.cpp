#include "Animation.h"

#include <iostream>
#include <string>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/System/Time.hpp>

void Animation::Load(float animSpeed, TextureManager::ID textureID)
{
	animationSpeed_ = animSpeed;

	textureID_ = textureID;

	sf::Image image({ 100,100 }, sf::Color::Magenta);
	defaultTexture_.loadFromImage(image);
}

void Animation::UpdateIdx(sf::Time dt)
{
	totalElapsed_ += dt;
	if (totalElapsed_.asSeconds() >= animationSpeed_) {
		// Picking next texture
		idxTextures_++;
		// Reset time
		totalElapsed_ = totalElapsed_.Zero;
		// Switch to first frame
		if (idxTextures_ >= TextureManager::GetTextures(textureID_).size())
		{
			idxTextures_ = 0;
		}
	}
}
const sf::Texture& Animation::GetTexture() const
{
	if (TextureManager::GetTextures(textureID_).size() > 0)
	{
		return TextureManager::GetTextures(textureID_)[idxTextures_];
	}

	return defaultTexture_;
}

void Animation::SetIndex(int index)
{
	idxTextures_ = index;
}

int Animation::GetIndex()
{
	return idxTextures_;
}