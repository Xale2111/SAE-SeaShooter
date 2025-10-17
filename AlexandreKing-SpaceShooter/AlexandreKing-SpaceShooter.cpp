// AlexandreKing-SpaceShooter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Animation.h"
#include "AudioManager.h"
#include "Player.h"
#include "ProjectileManager.h"

constexpr float winFrameRate = 60.f;
constexpr sf::Vector2f kCharacterSize(100, 100);

using namespace sf;

int main()
{

    srand(static_cast<unsigned>(time(nullptr)));

    AudioManager audio_manager;
    audio_manager.LoadAll();
    ProjectileManager projectileManager;
    projectileManager.Load("assets/sprites/Laser");
    

    Player player("assets/sprites/Character/", 0.175,100,10,0.3f);
    player.Load(&projectileManager);

    Animation turtleAnimation;
    turtleAnimation.Load("assets/sprites/Character/", 0.175);

    RenderWindow mainWindow(VideoMode({ 1920,1080 }), "See Shooter");

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
        player.AnimationUpdate();

        // Graphical Region
        mainWindow.clear(Color({ 87, 250, 215 }));

	    for (auto& projectile : projectileManager.GetAllProjectiles())
	    {
            mainWindow.draw(projectile);
            projectile.AnimationUpdate();
            if (projectile.Move() == ProjectileState::Destroyed)
            {
                projectileManager.AddProjectileToRemoveList(&projectile);
            }
	    }
        projectileManager.RemoveProjectiles();

        mainWindow.draw(player);

        // Window Display
        mainWindow.display();

    }

}