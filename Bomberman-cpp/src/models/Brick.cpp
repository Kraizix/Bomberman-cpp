#include "models/Brick.h"

Brick::Brick(const Vec2f& _position)
{
	SetPosition(_position);
	SetSprite("brick");
}
