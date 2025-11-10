#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Button.h"


constexpr float winMenuFrameRate = 60.f;
constexpr int winMenuWidth = 800;
constexpr int winMenuHeight = 600;

constexpr  int buttonWidth = 360;
constexpr  int buttonheight = 180;

enum class ActionCodes
{
	kQuit = -1,
	kDisplayMenu = 0,
	kPlay = 1,

};


class MenuWindow
{
private:
	sf::RenderWindow menuWindow = sf::RenderWindow(sf::VideoMode({winMenuWidth,winMenuHeight}),"Sea Shooter Menu");

	Button playButton;
	Button quitButton;

public:
	void Load();
	int Display();
};

