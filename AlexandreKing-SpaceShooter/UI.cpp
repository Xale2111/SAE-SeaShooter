#include "UI.h"

#include <iostream>

void UI::Load(RenderWindow& window)
{
	if (font_.openFromFile(fontPath + "Road_Rage.ttf"))
	{
		std::cout << "Didn't load font" << std::endl;
	}
	
	scoreLabel_ = sf::Text(font_);

	scoreLabel_->setCharacterSize(18);
	scoreLabel_->setFillColor(sf::Color::White);
	scoreLabel_->setPosition({ window.getSize().x - 300.f, window.getSize().y-50.f });
	scoreLabel_->setString("Score :");

}


void UI::draw(RenderTarget& target, RenderStates states) const
{
	if (scoreLabel_.has_value())
	{
		target.draw(scoreLabel_.value());
	}
}
