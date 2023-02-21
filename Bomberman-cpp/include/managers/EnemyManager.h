#pragma once
#include <vector>

#include "models/Entity.h"

class EnemyManager
{
public:
    EnemyManager()=delete;
    EnemyManager(std::vector<std::vector<Entity*>>& _map);
    bool AddEnemyToManager(Entity*);
    bool SetM_Entities(std::vector<std::vector<Entity*>>);
private:
    std::vector<Entity*> m_enemies;
    std::vector<std::vector<Entity*>>& m_map;
};
