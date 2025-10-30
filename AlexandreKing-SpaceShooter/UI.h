#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

const std::string fontPath = "assets/font/";

class UI : public sf::Drawable
{
private:
	RectangleShape bigFrame_;
	RectangleShape scoreFrame_;

	std::optional<Text>scoreLabel_;
	std::optional<Text>score_;

	RectangleShape lifeIcon_;

	Font font_;

protected:
	void draw(RenderTarget& target, RenderStates states) const override;

public:
	void Load(RenderWindow& window);


	
};
