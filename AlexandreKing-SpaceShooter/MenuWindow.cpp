#include "MenuWindow.h"

void MenuWindow::Load()
{
	menuWindow.setVerticalSyncEnabled(true);
	menuWindow.setFramerateLimit(winMenuFrameRate);
	

	playButton.SetSize({buttonWidth,buttonheight});
	playButton.SetPosition({ winMenuWidth / 2,winMenuHeight / 2 - (buttonheight/2 * 1.1) });
	playButton.SetFillColor(sf::Color(255,125,80));
	playButton.SetHoverColor(sf::Color(0, 255, 128));
	playButton.SetPressColor(sf::Color(0, 255, 0));
	playButton.SetActionCode((int)ActionCodes::kPlay);

	quitButton.SetSize({ buttonWidth,buttonheight });
	quitButton.SetPosition({ winMenuWidth / 2 ,winMenuHeight / 2 + (buttonheight/2 * 1.1) });
	quitButton.SetFillColor(sf::Color(255, 125, 80));
	quitButton.SetHoverColor(sf::Color(0, 255, 0));
	quitButton.SetPressColor(sf::Color(0, 80, 0));
	quitButton.SetActionCode((int)ActionCodes::kQuit);

}

int MenuWindow::Display()
{
	while (menuWindow.isOpen())
	{
		while (const std::optional event = menuWindow.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				menuWindow.close();
				return (int)ActionCodes::kQuit;
			}
			playButton.HandleInput(event);
			quitButton.HandleInput(event);
		}

		menuWindow.clear();

		


		playButton.CheckHover(sf::Vector2f(sf::Mouse::getPosition(menuWindow)));
		quitButton.CheckHover(sf::Vector2f(sf::Mouse::getPosition(menuWindow)));

		playButton.HandleState();
		quitButton.HandleState();


		menuWindow.draw(playButton);
		menuWindow.draw(quitButton);

		if (playButton.HasBeenPressed())
		{
			menuWindow.close();
			return  (int)ActionCodes::kPlay;
		}
		if (quitButton.HasBeenPressed())
		{
			menuWindow.close();
			return  (int)ActionCodes::kQuit;
		}

		menuWindow.display();

		return (int)ActionCodes::kDisplayMenu;


	}
}


