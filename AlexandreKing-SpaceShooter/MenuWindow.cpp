#include "MenuWindow.h"

#include <iostream>

void MenuWindow::ClosingWindow()
{
	isInMenu_ = false;
	menuWindow.close();
}

void MenuWindow::SetPlayButton()
{
	playButton_.SetFont(buttonFont_, 64);
	playButton_.SetFontColor(sf::Color::Black);
	playButton_.SetText("Play");
	playButton_.SetSize({ buttonWidth,buttonheight });
	playButton_.SetPosition({ winMenuWidth / 2,winMenuHeight / 2 - (buttonheight / 2 * 1.1) });
	playButton_.SetFillColor(sf::Color(31, 190, 239, 200));
	playButton_.SetHoverColor(sf::Color(93, 200, 216, 200));
	playButton_.SetPressColor(sf::Color(54, 119, 186, 200));
	playButton_.SetOutline(4, sf::Color::Black);
	playButton_.SetActionCode((int)ActionCodes::kPlay);
}

void MenuWindow::SetQuitButton()
{
	quitButton_.SetFont(buttonFont_, 64);
	quitButton_.SetFontColor(sf::Color::Black);
	quitButton_.SetText("Quit");
	quitButton_.SetSize({ buttonWidth,buttonheight });
	quitButton_.SetPosition({ winMenuWidth / 2 ,winMenuHeight / 2 + (buttonheight / 2 * 1.1) });
	quitButton_.SetFillColor(sf::Color(31, 190, 239, 200));
	quitButton_.SetHoverColor(sf::Color(93, 200, 216, 200));
	quitButton_.SetPressColor(sf::Color(54, 119, 186, 200));
	quitButton_.SetOutline(4, sf::Color::Black);
	quitButton_.SetActionCode((int)ActionCodes::kQuit);
}

void MenuWindow::SetMuteButton()
{
	float muteSize = 50.f;

	muteButton_.SetSize({ muteSize,muteSize });
	muteButton_.SetIcon("assets/menu/unmute.png");
	muteButton_.SetPosition({20,20});
	muteButton_.SetFillColor(sf::Color(31, 190, 239, 200));
	muteButton_.SetHoverColor(sf::Color(93, 200, 216, 200));
	muteButton_.SetPressColor(sf::Color(54, 119, 186, 200));
	muteButton_.SetOutline(4, sf::Color::Black);

}


void MenuWindow::Load()
{
	menuWindow.setVerticalSyncEnabled(true);
	menuWindow.setFramerateLimit(winMenuFrameRate);

	backgroundImage_.setSize({winMenuWidth, winMenuHeight});

	if (!bgTexture_.loadFromFile("assets/menu/background.JPG"))
	{
		std::cout << "background image wasn't load" << std::endl;
	}

	backgroundImage_.setTexture(&bgTexture_);
	backgroundImage_.setPosition({ 0,0 });

	if (!buttonFont_.openFromFile("assets/menu/Ocean-Rush-DEMO.ttf"))
	{
		std::cout << "Button font didn't load" << std::endl;
	}

	gameName_ = sf::Text(buttonFont_);
	gameName_->setString("LASER  SHOOTING  TURTLE !!!");
	gameName_->setCharacterSize(88);
	gameName_->setFillColor(sf::Color::Red);
	gameName_->setPosition({ winMenuWidth / 2 - gameName_->getGlobalBounds().size.x / 2 ,40});

	SetPlayButton();
	SetQuitButton();

	//SetMuteButton();

}

void MenuWindow::CreateWindow()
{
	if (!isInMenu_)
	{
		menuWindow.create(sf::VideoMode({ winMenuWidth,winMenuHeight }), "Sea Shooter Menu");
		isInMenu_ = true;
	}
}

int MenuWindow::Display()
{
	while (menuWindow.isOpen())
	{
		while (const std::optional event = menuWindow.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				ClosingWindow();
				return (int)ActionCodes::kQuit;
			}
			playButton_.HandleInput(event);
			quitButton_.HandleInput(event);
		}

		menuWindow.clear();


		playButton_.CheckHover(sf::Vector2f(sf::Mouse::getPosition(menuWindow)));
		quitButton_.CheckHover(sf::Vector2f(sf::Mouse::getPosition(menuWindow)));

		playButton_.HandleState();
		quitButton_.HandleState();


		menuWindow.draw(backgroundImage_);

		menuWindow.draw(*gameName_);
		menuWindow.draw(playButton_);
		menuWindow.draw(quitButton_);
		//menuWindow.draw(muteButton_);

		if (playButton_.HasBeenPressed())
		{
			ClosingWindow();
			playButton_.ResetPressState();
			return  (int)ActionCodes::kPlay;
		}
		if (quitButton_.HasBeenPressed())
		{
			ClosingWindow();
			quitButton_.ResetPressState();
			return  (int)ActionCodes::kQuit;
		}

		menuWindow.display();

		return (int)ActionCodes::kDisplayMenu;


	}
}


