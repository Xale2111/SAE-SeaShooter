#include "UI.h"

#include <iostream>

void UI::Load(RenderWindow& window)
{
	if (font_.openFromFile(fontPath + "Road_Rage.ttf"))
	{
		std::cout << "Didn't load font" << std::endl;
	}
	/*
	if (!scoreLabel_.has_value())
	{
		scoreLabel_ = Text(font_);
		scoreLabel_->setCharacterSize(18);
		scoreLabel_->setFillColor(Color::Black);
		scoreLabel_->setPosition({ static_cast<float>(window.getSize().x / 2),50 });
		scoreLabel_->setString("Score : ");
	}*/
}


void UI::draw(RenderTarget& target, RenderStates states) const
{
	//target.draw(scoreLabel_.value());
}
