#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class Animation
{
private:
	std::vector<sf::Texture> textures_;
	int idxTextures_ = 0;

	sf::Clock clock_;
	sf::Time totalElapsed_;
	float animationSpeed_;

	bool isPlaying_ = true;

	sf::Texture defaultTexture_;

public:
	bool Load(std::string path, float animSpeed);
	void UpdateIdx();
	void Play();
	void Pause();

	const sf::Texture* GetTexture() const;

	void OnEnd();

	const void Update();
	const bool IsPlaying();

};