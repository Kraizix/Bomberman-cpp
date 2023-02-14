#include "models/Block.h"

Block::Block(const Vec2f& _position)
{
	SetPosition(_position);
	SetSprite("block");
}
