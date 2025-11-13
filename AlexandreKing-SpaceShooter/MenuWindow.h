#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

#include "Button.h"


constexpr float winMenuFrameRate = 60.f;
constexpr int winMenuWidth = 1200;
constexpr int winMenuHeight = 900;

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
	sf::RenderWindow menuWindow;

	sf::Texture bgTexture_;
	sf::RectangleShape backgroundImage_;

	sf::Font menuFont_;

	std::optional<sf::Text> gameName_;
	std::optional<sf::Text> lastScoreLabel_;
	std::optional<sf::Text> lastScoreValue_;

	Button playButton_;
	Button quitButton_;
	Button muteButton_;

	bool isInMenu_ = false;

	void ClosingWindow();

	void SetPlayButton();
	void SetQuitButton();
	void SetMuteButton();

public:
	void Load();
	void CreateWindow();
	void SetLastScore(int lastScoreValue);
	int Display();
};

