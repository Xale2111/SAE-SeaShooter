#include "TextureManager.h"

#include <filesystem>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>

namespace TextureManager
{
	namespace 
	{
		std::unordered_map<ID, std::vector<sf::Texture>> textures_;
	}

	bool Load(ID id, std::string path)
	{
		if (std::filesystem::is_empty(path)) return false;
		if (textures_.contains(id)) return false;

		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			if (entry.path().extension() != ".png")
			{
				std::cout << "Wrong file extension.\n";
				textures_[id].clear();
				return false;
			}
			sf::Texture texture;
			textures_[id].emplace_back(entry.path());
		}
		return true;
	}

	std::vector<sf::Texture>& GetTextures(ID id)
	{
		return textures_[id];
	}
}
