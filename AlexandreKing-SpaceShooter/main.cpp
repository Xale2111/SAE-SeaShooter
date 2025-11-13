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
#include "TextureManager.h"
#include "UI.h"

int main()
{
    //Variables that needs to be persistent throughout the different windows
    bool isRunning = true;
    int actionCode = 0;

    int lastScore = 0;


    TextureManager::Load(TextureManager::ID::kTurtleNormal, "assets/sprites/character/normal");
    TextureManager::Load(TextureManager::ID::kTurtleInvincible, "assets/sprites/character/invincible");

    TextureManager::Load(TextureManager::ID::kEasyEnemy, "assets/sprites/enemy/easy/");
    TextureManager::Load(TextureManager::ID::kMediumEnemy, "assets/sprites/enemy/medium/");
    TextureManager::Load(TextureManager::ID::kHardEnemy, "assets/sprites/enemy/hard/");
    TextureManager::Load(TextureManager::ID::kHardcoreEnemy, "assets/sprites/enemy/hardcore/");

    TextureManager::Load(TextureManager::ID::kEasyMediumProjectile,"assets/sprites/laser/enemy/all");
    TextureManager::Load(TextureManager::ID::kHardHardcoreProjectile, "assets/sprites/laser/enemy/hard");
    TextureManager::Load(TextureManager::ID::kPlayerProjectile, "assets/sprites/laser/player");

    TextureManager::Load(TextureManager::ID::kPlasticBag, "assets/sprites/meteor/bag");
    TextureManager::Load(TextureManager::ID::kPlasticBottle, "assets/sprites/meteor/bottle");
    TextureManager::Load(TextureManager::ID::kTrash, "assets/sprites/meteor/trash");
    TextureManager::Load(TextureManager::ID::kLouis, "assets/sprites/meteor/louis");


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