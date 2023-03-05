#include "models/Enemy.h"
#include <random>
#include <iostream>

Enemy::Enemy(const Vec2f& position)
{
    m_direction = nullptr;
    m_steps = 0;
    m_speed = 1.0f;
    m_speedCoeficient = 1.0f;
    SetPosition(position);
    m_destroyable = true;
    SetEntityType(TEnemy);
    SetSprite("F1");
    GetNextPosition();
}

void Enemy::Move(std::vector<std::vector<Entity*>> Map, float deltaT)
{
    Vec2f* currentPosition = GetPosition();
    float x1, x2, y1, y2;
    if (m_direction->x != 0)
    {
        x1 = m_direction->x == 1 ? ceil(currentPosition->x - 0.05f) : floor(currentPosition->x + 0.05);
        x2 = m_direction->x == 1 ? ceil(currentPosition->x - 0.05) : floor(currentPosition->x + 0.05);
        y1 = floor(currentPosition->y + 0.05);
        y2 = ceil(currentPosition->y - 0.05);
    }
    else if (m_direction->y != 0)
    {
        x1 = floor(currentPosition->x + 0.05f);
        x2 = ceil(currentPosition->x - 0.05f);
        y1 = m_direction->y == 1 ? ceil(currentPosition->y - 0.05) : floor(currentPosition->y + 0.05);
        y2 = m_direction->y == 1 ? ceil(currentPosition->y - 0.05) : floor(currentPosition->y + 0.05);
    }

    //std::cout << x1 <<" : " << y1 << " // " << x2 << " : " << y2 << std::endl;
    //std::cout << Map[y1][x1]->GetEntityType() << " // " << Map[y2][x2]->GetEntityType() << std::endl << std::endl;

    if (m_steps<=0 || 
        Map[y1][x1]->GetEntityType() != TGrass && Map[y2][x2]->GetEntityType() == TGrass)
    {
        m_steps = 0;
        GetNextPosition();
        Move(Map, deltaT);
        return;
    }

    //std::cout << std::round(GetPosition()->y + m_direction->y) << " " << std::round(GetPosition()->x + m_direction->x) << std::endl;

    Vec2f move = *m_direction;
    //détermine the movement
    move.x *= (m_speed * m_speedCoeficient);
    move.y *= (m_speed * m_speedCoeficient);
    SetPosition((*currentPosition).Add(move*deltaT));
    m_steps -= 64*deltaT;
    std::cout << m_steps << std::endl;
}

void Enemy::GetNextPosition()
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
