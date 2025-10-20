#include "Animation.h"

#include <iostream>
#include <string>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/System/Time.hpp>

namespace sf
{
	class Texture;
}

bool Animation::Load(std::string path, float animSpeed)
{
	animationSpeed_ = animSpeed;

	if (std::filesystem::is_empty(path))
	{
		return false;
	}

	sf::Image image({ 100,100 }, sf::Color::Magenta);
	defaultTexture_.loadFromImage(image);

	// Load every textures--------------------------------------------------------------------------------------------------
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		if (entry.path().extension() != ".png")
		{
			std::cout << "Wrong file extension.\n";
			textures_.clear();
			return false;
		}

		textures_.emplace_back(entry.path());
	}

	return true;

}

void Animation::UpdateIdx()
{
	sf::Time elapsed = clock_.restart();
	totalElapsed_ = totalElapsed_ + elapsed;
	if (totalElapsed_.asSeconds() >= animationSpeed_) {
		// Picking next texture
		idxTextures_++;
		// Reset time
		totalElapsed_ = totalElapsed_.Zero;
		// Switch to first frame
		if (idxTextures_ >= textures_.size())
		{
			idxTextures_ = 0;
		}
	}
}

const void Animation::Update()
{
	// Every 100ms, we load a new texture
	if (isPlaying_) {
		UpdateIdx();
	}
}

void Animation::Play()
{
	isPlaying_ = true;
}

void Animation::Pause()
{
	isPlaying_ = false;
}

const sf::Texture* Animation::GetTexture() const
{
	if (textures_.size() > 0)
	{
		return &textures_[idxTextures_];
	}

	return &defaultTexture_;
}

const bool Animation::IsPlaying()
{
	return isPlaying_;
}
