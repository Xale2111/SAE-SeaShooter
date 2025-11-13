#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "TextureManager.h"

using namespace TextureManager;

class Animation
{
private:
	int idxTextures_ = 0;

	TextureManager::ID textureID_  = TextureManager::ID::kNone;

	sf::Time totalElapsed_;
	float animationSpeed_;

	sf::Texture defaultTexture_;

public:
	void Load(float animSpeed, TextureManager::ID textureID);
	void UpdateIdx(sf::Time dt);

	const sf::Texture& GetTexture() const;

	void SetIndex(int index);
	int GetIndex();

};
