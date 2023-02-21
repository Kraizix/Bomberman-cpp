#include "models/Wall.h"

Wall::Wall(const Vec2f& _position)
{
	SetPosition(_position);
	SetSprite("wall");
	SetEntityType(TWall);
}
