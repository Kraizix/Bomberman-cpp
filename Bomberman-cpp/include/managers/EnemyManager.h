#pragma once
#include <vector>

#include "models/Entity.h"
#include <models/Enemy.h>

class EnemyManager
{
public:
    EnemyManager()=delete;
    EnemyManager(std::vector<std::vector<Entity*>>& _map);
    static EnemyManager* GetInstance(std::vector<std::vector<Entity*>>& _map);
    void RenderEnemies(sf::RenderTarget&, const Vec2f&);
    void MoveEnemies(float*);
    void PushM_Enemy(Enemy*);
private:
    static EnemyManager* m_instance;
    std::vector<Enemy*> m_enemies;
    std::vector<std::vector<Entity*>>& m_map;
};
