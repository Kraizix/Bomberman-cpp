#include "./managers/EnemyManager.h"
#include <managers/LevelManager.h>

EnemyManager::EnemyManager(std::vector<std::vector<Entity*>>& _map):m_map(_map)
{
}

EnemyManager* EnemyManager::m_instance = nullptr;

EnemyManager* EnemyManager::GetInstance(std::vector<std::vector<Entity*>>& _map)
{
    if (m_instance == nullptr)
    {
        m_instance = new EnemyManager(_map);
    }

    return m_instance;
}

void EnemyManager::RenderEnemies(sf::RenderTarget& _target, const Vec2f& _tileSize)
{
    for (auto& enemy : m_enemies)
    {
        enemy->SetSize(_tileSize);
        enemy->Render(_target);
    }
}

void EnemyManager::PushM_Enemy(Enemy* entity)
{    
    m_enemies.push_back(entity);
}

void EnemyManager::MoveEnemies(float* DeltaT)
{
    
    for (Enemy* enemy : m_enemies)
    {
        enemy->Move(m_map,DeltaT,LevelManager::GetInstance()->GetLevel()->GetPlayer());
    }
}
