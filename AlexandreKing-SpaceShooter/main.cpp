// AlexandreKing-SpaceShooter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <random>

#include "Animation.h"
#include "AudioManager.h"
#include "EnemyManager.h"
#include "MeteorManager.h"
#include "Player.h"
#include "ProjectileManager.h"
#include "UI.h"

constexpr float winFrameRate = 60.f;
constexpr int winWidth = 1920;
constexpr int winHeight = 1080;

using namespace sf;

int main()
{
    AudioManager audioManager;
    audioManager.LoadAll();
    ProjectileManager projectileManager;
    projectileManager.Load();

    EnemyManager enemyManager(projectileManager, audioManager);
    enemyManager.SetAllWaves();

    MeteorManager meteorManager;
    meteorManager.Load();

    Player player("assets/sprites/Character/", 0.175,250,40,0.2f, EntityType::kPlayer);
    player.Load(&projectileManager, &audioManager);
    player.SetCollider();
    player.DefineAll(&meteorManager);

    UI ui;

    Clock clock;


    //Window
    RenderWindow mainWindow(VideoMode({ winWidth,winHeight}), "Sea Shooter");

    mainWindow.setVerticalSyncEnabled(true);
    mainWindow.setFramerateLimit(winFrameRate);
	mainWindow.setPosition({ 0,0 });
    mainWindow.setMouseCursorVisible(false);

    ui.Load(mainWindow);


    while (mainWindow.isOpen())
    {
        Time deltaTime = clock.restart();


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
                    player.SetIsShooting(true);
	            }
            }
            else if (const auto* mouseReleased = event->getIf<Event::MouseButtonReleased>())
            {
	            if (mouseReleased->button == Mouse::Button::Left)
	            {
                    player.SetIsShooting(false);
	            }
            }
        }

        player.Shoot(deltaTime);

        enemyManager.Spawn(deltaTime);
        meteorManager.SpawnMeteor(deltaTime);

        // Visual Update
        mainWindow.clear(Color({ 87, 250, 215 }));

        //Lowest drawed item
        //draw projectiles
	    for (auto& projectile : projectileManager.GetAllProjectiles())
	    {
            projectile.AnimationUpdate();
            mainWindow.draw(projectile);
            if (projectile.Move(deltaTime) == ObjectState::kDestroyed)
            {
                projectileManager.AddProjectileToRemoveList(&projectile);
            }
	    }
        projectileManager.RemoveProjectiles();

        //second layer
        //draw enemies
        for (auto& enemy : enemyManager.GetAllEnemies())
        {
            enemy.SetDeltaTime(deltaTime);
            enemy.AnimationUpdate();
        	enemy.Move();
            mainWindow.draw(enemy);
            enemy.Shoot();
            enemy.DetectCollision();
            if (enemy.GetState() == ObjectState::kDestroyed)
            {
                player.AddScore(enemy.GetPointValue());
                enemyManager.AddEnemyToRemove(enemy);
                audioManager.PlayExplosionSoundEffect();
            }
        }

        enemyManager.RemoveEnemies();

        //third layer
        player.AnimationUpdate();
        player.DetectCollision();
        mainWindow.draw(player);

        //Top layer
        //Draw plastic bags
        for (auto& meteor : meteorManager.GetAllMeteors())
        {
            meteor.AnimationUpdate();
            mainWindow.draw(meteor);
            meteor.IncreaseRotation();

        	if (meteor.Move(deltaTime) == ObjectState::kDestroyed)
            {
                meteorManager.AddRemoveMeteor(meteor);
            }
        }
        meteorManager.RemoveMeteors();

        //Display UI
        mainWindow.draw(ui);

        // Window Display
        mainWindow.display();
    }

}