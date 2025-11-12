#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

const std::string fontPath = "assets/font/";
const float CHAR_SIZE = 9.5f;
const float HEALTH_BAR_ORIGIN_SIZE = 500.f;
const float OFFSET_FROM_BOTTOM = 50.f;

class UI : public sf::Drawable
{
private:
	std::optional<Text> scoreLabel_;
	RectangleShape healthBar_;
		

	float scoreOriginPositionX_;
	int playerMaxHealth;

	Font font_;
	const void ChangeScoreValue();


protected:
	void draw(RenderTarget& target, RenderStates states) const override;

public:
	void UpdateScorevalue(int playerScore);
	void UpdateHealthBar(int playerHealth);
	void UpdatePlayerMaxHealth(int newMaxHealth);

	void Load(RenderWindow& window, int playerHealthAtStart);


	
};
