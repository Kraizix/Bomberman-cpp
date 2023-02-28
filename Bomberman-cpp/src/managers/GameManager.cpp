#include "managers/GameManager.h"
#include "managers/AssetManager.h"
#include "managers/WindowManager.h"
#include "managers/LevelManager.h"
#include <iostream>
#include <models/Player.h>
#include <managers/EnemyManager.h>

GameManager* GameManager::m_instance = nullptr;


GameManager* GameManager::GetInstance()
{
    if (m_instance == nullptr) {
        m_instance = new GameManager();
    }
    
    return m_instance;

}

GameManager::GameManager()
{

}

GameManager::~GameManager() {
    if (m_instance != nullptr)
    {
        delete m_instance;
    }
}

bool GameManager::Run(const std::string& _title, const Vec2i& _size)
{
    bool success = LoadResources();
    if (!success)
        return false;

    WindowManager* windowManager = WindowManager::GetInstance();
    if (windowManager == nullptr)
        return false;

    sf::RenderWindow* window = windowManager->CreateWindow(_title, _size.x, _size.y);
    if (window == nullptr)
    {
        std::cout << ">> Cannot create window !" << std::endl;
        return false;
    }

    LevelManager* levelManager = LevelManager::GetInstance();
    if (levelManager == nullptr)
        return false;
    Level* level = levelManager->LoadLevel("resources/levels/level.txt");
    Player* player = level->GetPlayer();
    if (level == nullptr)
        return false;
    EnemyManager* enemyManager = EnemyManager::GetInstance(level->GetMap());
    if (enemyManager == nullptr)
        return false;
    const Vec2f tileSize = { 64.0f, 64.0f };
    Vec2f levelSize = level->GetSize(tileSize);
    std::cout << "Level Size : (" << levelSize.x << " x " << levelSize.y << ")" << std::endl;
    float ratioW = levelSize.x / _size.x;
    float ratioH = levelSize.y / _size.y;
    std::cout << "Level ratio : (" << ratioW << " x " << ratioH << ")" << std::endl;
    float centerX = (levelSize.x + _size.x) / 2;
    float centerY = (levelSize.y + _size.y) / 2;
    std::cout << "Level center : (" << centerX << " x " << centerY << ")" << std::endl;
    sf::View view(sf::FloatRect(0.f, 0.f, _size.x, _size.y));

    while (window->isOpen())
    {   
        sf::Event event;
        while (window->pollEvent(event))
        {
            switch (event.type) 
            {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::Q:
                    level->MovePlayer(player->Move({ -1,0 }));
                    break;

                case sf::Keyboard::S:
                    level->MovePlayer(player->Move({ 0,1 }));
                    break;

                case sf::Keyboard::Z:
                    level->MovePlayer(player->Move({ 0,-1 }));
                    break;

                case sf::Keyboard::D:
                    level->MovePlayer(player->Move({ 1,0 }));
                    break;
                }
            }
        }
        enemyManager->MoveEnemies();
        window->clear();
        window->setView(view);
        level->RenderLevel(*window, tileSize);
        window->display();
    }
    return true;
}

bool GameManager::LoadResources()
{
    bool success = true;
    AssetManager* assetManager = AssetManager::GetInstance();

    success &= assetManager->LoadTexture("map_assets/brick.png", "brick");
    success &= assetManager->LoadTexture("map_assets/wall.png", "wall");
    success &= assetManager->LoadTexture("map_assets/grass.png", "grass");
    success &= assetManager->LoadTexture("mc_animations/F1.png", "F1");

    if (success)
    {
        std::cout << ">> Loading resources was successful !" << std::endl;
    }
    else
    {
        std::cout << ">> Error while loading resources !" << std::endl;
        return false;
    }

    return true;
}
