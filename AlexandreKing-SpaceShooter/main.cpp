// AlexandreKing-SpaceShooter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <random>

#include "Animation.h"
#include "AudioManager.h"
#include "EnemyManager.h"
#include "GameWindow.h"
#include "MenuWindow.h"
#include "MeteorManager.h"
#include "Player.h"
#include "ProjectileManager.h"
#include "UI.h"

int main()
{

    bool isRunning = true;
    int actionCode = 0;

    int lastScore = 0;

    GameWindow gameWindow;
    gameWindow.Load();

    MenuWindow menuWindow;
    menuWindow.Load();

    while (isRunning)
    {
	    switch (actionCode)
	    {
	    case (int)ActionCodes::kDisplayMenu:
            menuWindow.CreateWindow();
            menuWindow.SetLastScore(lastScore);
            actionCode = menuWindow.Display();
            break;
	    case (int)ActionCodes::kPlay:
            gameWindow.Start();
            gameWindow.Play();
            if (!gameWindow.WindowIsOpen())
            {
                actionCode = (int)ActionCodes::kDisplayMenu;
                lastScore = gameWindow.GetFinalScore();
                gameWindow.ResetGame();
            }

            break;
	    case (int)ActionCodes::kQuit:
            isRunning = false;
            break;
	    }
    }

    return 0;
}