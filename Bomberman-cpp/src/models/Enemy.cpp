#include "models/Enemy.h"

Enemy::Enemy(const Vec2f& position)
{
      SetPosition(position);
      m_destroyable = true;
      SetEntityType(TEnemy);
}

bool Enemy::Move(std::vector<std::vector<Entity*>> Entities)
{
      return true;
}

void Enemy::GetNextPosition(std::vector<std::vector<Entity*>> Entities)
{
      m_nextPosition = new Vec2f();
}
