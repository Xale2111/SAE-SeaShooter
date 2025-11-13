#pragma once

#include <string>
#include <unordered_map>
#include <SFML/Graphics/Texture.hpp>

namespace TextureManager
{
	enum class ID
	{
		kTurtleNormal,
		kTurtleInvincible,

		kPlayerProjectile,
		kEasyMediumProjectile,
		kHardHardcoreProjectile,

		kEasyEnemy,
		kMediumEnemy,
		kHardEnemy,
		kHardcoreEnemy,

		kPlasticBottle,
		kPlasticBag,
		kTrash,
		kLouis,

		kNone,
	};

	
	bool Load(ID id, std::string path);
	
	std::vector<sf::Texture>& GetTextures(ID id);
}