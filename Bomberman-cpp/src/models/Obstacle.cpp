#include "models/Obstacle.h"

Obstacle::Obstacle(const Vec2f& _position)
{
	SetPosition(_position);
	SetSprite("obstacle");
}
