#include "./managers/EnemyManager.h"

EnemyManager::EnemyManager(std::vector<std::vector<Entity*>>& _map):m_map(_map)
{
}

bool EnemyManager::AddEnemyToManager(Entity* enemy)
{
    m_enemies.push_back(enemy);
    return true;
}

bool EnemyManager::SetM_Entities(std::vector<std::vector<Entity*>> map)
{
    m_map = map;
    for (std::vector<Entity*> entityRow : map)
    {
        for (Entity* entity : entityRow)
        {
            //if (entity = TYPE.Enemy)
            //m_enemies.push_back(entity)
        }
    }
    return true;
}
