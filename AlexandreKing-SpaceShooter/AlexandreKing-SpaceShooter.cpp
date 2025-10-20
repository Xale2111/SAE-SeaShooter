// AlexandreKing-SpaceShooter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Animation.h"
#include "AudioManager.h"
#include "EnemyManager.h"
#include "Player.h"
#include "ProjectileManager.h"

constexpr float winFrameRate = 60.f;
constexpr int winWidth = 1920;
constexpr int winHeight = 1080;

using namespace sf;

int main()
{

    srand(static_cast<unsigned>(time(nullptr)));

    AudioManager audio_manager;
    audio_manager.LoadAll();
    ProjectileManager projectileManager;
    projectileManager.Load();

    
    Enemy easyEnemy(enemiesSpritesPath + "easy/", 0.2f, 50, 10, 0.4f,EntityType::kEasyEnemy, 1, 1, 20, { 0,0 }, 100);
	Enemy mediumEnemy(enemiesSpritesPath + "medium/", 0.2f, 100, 25, 1, EntityType::kEasyEnemy, 0.5, 1, 50, { 0,0 }, 110);
	Enemy hardEnemy(enemiesSpritesPath + "hard/", 0.2f, 200, 35, 0.35f, EntityType::kEasyEnemy, 0.75, 3, 100, { 0,0 }, 125);
    Enemy hardcoreEnemy(enemiesSpritesPath + "hardcore/", 0.2f, 500, 50, 1, EntityType::kEasyEnemy, 0.5, 5, 250, { 0,0 }, 80);

    easyEnemy.Load(&projectileManager);
    mediumEnemy.Load(&projectileManager);
    hardEnemy.Load(&projectileManager);
    hardcoreEnemy.Load(&projectileManager);

    EnemyManager enemyManager;
    enemyManager.DefineEnemies(&easyEnemy, &mediumEnemy, &hardEnemy, &hardcoreEnemy);
    enemyManager.SetAllWaves();
    //enemyManager.AddEnemy(&easyEnemy, { winWidth / 2,-100 });

    Player player("assets/sprites/Character/", 0.175,100,10,0.3f, EntityType::kPlayer);
    player.Load(&projectileManager);

    RenderWindow mainWindow(VideoMode({ winWidth,winHeight}), "Sea Shooter");

    mainWindow.setVerticalSyncEnabled(true);
    mainWindow.setFramerateLimit(winFrameRate);
	mainWindow.setPosition({ 0,0 });

    mainWindow.setVerticalSyncEnabled(true);
    mainWindow.setFramerateLimit(30);
    mainWindow.setMouseCursorVisible(false);
    

    while (mainWindow.isOpen())
    {
	    if (Mouse::getPosition().x > mainWindow.getSize().x)
	    {
            Mouse::setPosition({ 0,Mouse::getPosition().y });
	    }
	    else if (Mouse::getPosition().x < 0)
	    {
            Mouse::setPosition({ (static_cast<int>(mainWindow.getSize().x)) ,Mouse::getPosition().y });
	    }

        player.setPosition(static_cast<Vector2f>(Mouse::getPosition()));
        while (const std::optional event = mainWindow.pollEvent())
        {

            enemyManager.Spawn();

            if (event->is<sf::Event::Closed>())
            {
                mainWindow.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    mainWindow.close();
            }
            else if (const auto* mousePressed = event->getIf<Event::MouseButtonPressed>())
            {
	            if (mousePressed->button == Mouse::Button::Left)
	            {
                    audio_manager.PlayLaserSoundEffect();
                    player.Shoot();
	            }   
            }
        }

        // Visual Update
        mainWindow.clear(Color({ 87, 250, 215 }));

        //Lowest drawed item

	    for (auto& projectile : projectileManager.GetAllProjectiles())
	    {
            projectile.AnimationUpdate();
            mainWindow.draw(projectile);
            if (projectile.Move() == ProjectileState::Destroyed)
            {
                projectileManager.AddProjectileToRemoveList(&projectile);
            }
	    }
        projectileManager.RemoveProjectiles();

        //second layer
        //draw enemies
	    for (auto& enemy : enemyManager.GetAllEnemies())
	    {
            enemy.AnimationUpdate();
            mainWindow.draw(enemy);
            enemy.Move();
            enemy.Shoot();
	    }

        //third layer
        player.AnimationUpdate();
        mainWindow.draw(player);

        //Top layer
        //Draw plastic bags


        // Window Display
        mainWindow.display();

    }

}