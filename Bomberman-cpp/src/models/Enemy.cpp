#include "models/Enemy.h"
#include <random>
#include <iostream>

Enemy::Enemy(const Vec2f& position)
{
    m_direction = nullptr;
    m_steps = 0;
    m_speed = 0.03f;
    m_speedCoeficient = 1.0f;
    SetPosition(position);
    m_destroyable = true;
    SetEntityType(TEnemy);
    SetSprite("F1");
}

void Enemy::Move(std::vector<std::vector<Entity*>> Map)
{
    Vec2f* currentPosition = GetPosition();
    if (m_steps<=0 || 
        Map.at(std::round(GetPosition()->y + m_direction->y)).at(std::round(GetPosition()->x + m_direction->x))->GetEntityType() != TGrass) 
    {
        m_steps = 
        GetNextPosition(Map);
        Move(Map);
        return;
    }

    //std::cout << std::round(GetPosition()->y + m_direction->y) << " " << std::round(GetPosition()->x + m_direction->x) << std::endl;

    Vec2f move = *m_direction;
    //détermine the movement
    move.x *= (m_speed * m_speedCoeficient) / RATE;
    move.y *= (m_speed * m_speedCoeficient) / RATE;
    SetPosition((*currentPosition).Add(move));
    m_steps -= 1;
}

void Enemy::GetNextPosition(std::vector<std::vector<Entity*>> Map)
{
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(3, 10);

    //generate a direction
    // take a nbr of step to do

    int rnd = dist6(rng);
    m_direction = new Vec2f();
    if (rnd <= 4) {
        m_direction->Set(1, 0);
    }
    else if (rnd <= 6) {
        m_direction->Set(-1, 0);
    }
    else if (rnd <= 8) {
        m_direction->Set(0, 1);
    }
    else if (rnd <= 10) {
        m_direction->Set(0, -1);
    }

    m_steps = dist6(rng)*64;
}
