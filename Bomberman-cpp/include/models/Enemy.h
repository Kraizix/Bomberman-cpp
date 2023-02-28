#pragma once
#include "Entity.h"

#define RATE 30

class Enemy : public Entity
{
public:
    Enemy(const Vec2f&);
    void Move(std::vector<std::vector<Entity*>>);
    void GetNextPosition(std::vector<std::vector<Entity*>>);
private:
    Vec2f* m_direction;
    int m_steps;
    float m_speed;
    float m_speedCoeficient;
};
