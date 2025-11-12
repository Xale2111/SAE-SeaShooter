#include "UI.h"

#include <iostream>

void UI::Load(RenderWindow& window, int playerHealthAtStart)
{
	playerMaxHealth = playerHealthAtStart;

	if (font_.openFromFile(fontPath + "Road_Rage.ttf"))
	{
		std::cout << "Didn't load font" << std::endl;
	}
	
	scoreLabel_ = sf::Text(font_);

	scoreLabel_->setCharacterSize(28);
	scoreLabel_->setFillColor(sf::Color::White);
	scoreOriginPositionX_ = window.getSize().x - 220.f;
	scoreLabel_->setPosition({ scoreOriginPositionX_, window.getSize().y-OFFSET_FROM_BOTTOM });
	scoreLabel_->setString("Score : 0 pts");

	healthBar_.setSize({ HEALTH_BAR_ORIGIN_SIZE,25 });
	healthBar_.setFillColor(Color::Green);
	healthBar_.setPosition({20.f, window.getSize().y - OFFSET_FROM_BOTTOM });
}

void UI::UpdateScorevalue(int playerScore)
{
	scoreLabel_->setPosition({ scoreOriginPositionX_-(std::to_string(playerScore).size()*CHAR_SIZE),scoreLabel_->getPosition().y });
	scoreLabel_->setString("Score : " + std::to_string(playerScore) + " pts");
}

void UI::UpdateHealthBar(int playerHealth)
{
	float newXSize = (HEALTH_BAR_ORIGIN_SIZE/playerMaxHealth)*playerHealth;
	newXSize <= 0 ? healthBar_.setSize({ 0,25 }) :healthBar_.setSize({ newXSize,25 });
	;
	if (newXSize >= HEALTH_BAR_ORIGIN_SIZE*0.5f)
	{
		healthBar_.setFillColor(Color::Green);
	}
	else if (newXSize < HEALTH_BAR_ORIGIN_SIZE*0.5f && newXSize >= HEALTH_BAR_ORIGIN_SIZE *0.2f)
	{
		healthBar_.setFillColor(Color::Yellow);
	}
	else if (newXSize < HEALTH_BAR_ORIGIN_SIZE *0.2f)
	{
		healthBar_.setFillColor(Color::Red);
	}
}

void UI::UpdatePlayerMaxHealth(int newMaxHealth)
{
	playerMaxHealth = newMaxHealth;
}

void UI::draw(RenderTarget& target, RenderStates states) const
{
	if (scoreLabel_.has_value())
	{
		target.draw(scoreLabel_.value());
	}
	target.draw(healthBar_);
}
