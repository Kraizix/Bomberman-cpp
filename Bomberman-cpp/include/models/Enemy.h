#pragma once
#include "Entity.h"

class Enemy : Entity
{
public:
    Enemy(const Vec2f&);
    bool Move(std::vector<std::vector<Entity*>>);
    void GetNextPosition(std::vector<std::vector<Entity*>>);
private:
    Vec2f* m_nextPosition;
};
