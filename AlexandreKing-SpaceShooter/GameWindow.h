#pragma once

#include <SFML/Graphics.hpp>

#include "Animation.h"
#include "AudioManager.h"
#include "EnemyManager.h"
#include "MeteorManager.h"
#include "Player.h"
#include "ProjectileManager.h"
#include "UI.h"

constexpr float winGameFrameRate = 60.f;
constexpr int winGameWidth = 1920;
constexpr int winGameHeight = 1080;

const int playerHealth = 250;

class GameWindow
{
private:
    AudioManager audioManager;
    ProjectileManager projectileManager;

    EnemyManager enemyManager = EnemyManager(projectileManager, audioManager);
    MeteorManager meteorManager;
    Player player = Player(playerHealth, 40, 0.2f, EntityType::kPlayer);

    UI ui;

    sf::Clock clock;

    bool isInGame = false;

    RenderWindow mainWindow = RenderWindow(sf::VideoMode({ winGameWidth,winGameHeight }), "Sea Shooter");
public:
	void Load();
    void Start();
	void Play();
};

