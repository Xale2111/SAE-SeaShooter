#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

const std::string fontPath = "assets/font/";
const float CHAR_SIZE = 6.5f;
const float HEALTH_BAR_ORIGIN_SIZE = 400.f;
const float OFFSET_FROM_BOTTOM = 30.f;

class UI : public sf::Drawable
{
private:
	std::optional<Text> scoreLabel_;
	RectangleShape healthBar_;
		

	float scoreOriginPositionX_;
	int defaultPlayerHealth;

	Font font_;
	const void ChangeScoreValue();


protected:
	void draw(RenderTarget& target, RenderStates states) const override;

public:
	void UpdateScorevalue(int playerScore);
	void UpdateHealthBar(int playerHealth);

	void Load(RenderWindow& window, int playerHealthAtStart);


	
};
