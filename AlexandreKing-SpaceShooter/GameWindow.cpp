#include "GameWindow.h"

void GameWindow::Load()
{
    audioManager.LoadAll();
    projectileManager.Load();

    enemyManager.SetAllWaves();

    meteorManager.Load();

    player.Load(&projectileManager, &audioManager);
    player.SetCollider();
    player.DefineAll(&meteorManager, "assets/sprites/character/normal", 0.175f, "assets/sprites/character/invincible", 0.1f);

    //Window
    mainWindow.setVerticalSyncEnabled(true);
    mainWindow.setFramerateLimit(winGameFrameRate);
    mainWindow.setPosition({ 0,0 });
    mainWindow.setMouseCursorVisible(false);

    ui.Load(mainWindow, playerHealth);
    clock.stop();
}

void GameWindow::Start()
{
    if (!isInGame)
    {
        clock.reset();
        clock.start();
        isInGame = true;
    }
}

void GameWindow::Play()
{
	
    while (mainWindow.isOpen() && isInGame)
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
        player.MakePlayerInvicible(deltaTime);
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
        ui.UpdateScorevalue(player.GetScore());
        ui.UpdateHealthBar(player.GetHealthPoints());
        mainWindow.draw(ui);

        // Window Display
        mainWindow.display();

        if (player.GetHealthPoints() <= 0)
        {
            isInGame = false;
        }
    }
}
