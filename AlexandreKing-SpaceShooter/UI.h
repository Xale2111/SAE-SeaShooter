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
	std::optional<Text> roundCounterLabel_;
		
	int roundCounterValue_ = 1;
	Vector2f windowSize_;

	float scoreOriginPositionX_;
	int playerMaxHealth;

	Time newRound_;
	bool displayNewRoundText = false;

	Font font_;
	const void ChangeScoreValue();
	void NewRound();

protected:
	void draw(RenderTarget& target, RenderStates states) const override;

public:
	void UpdateScorevalue(int playerScore);
	void UpdateHealthBar(int playerHealth);
	void UpdatePlayerMaxHealth(int newMaxHealth);

	void StartingNewRound(bool isANewRoundStarting);
	void UpdateNewRoundText(Time dt);

	void Load(RenderWindow& window, int playerHealthAtStart);

};
