#pragma once
#include "models/Entity.h"

class Block : public Entity
{
public:
	Block(const Vec2f& _position);
	virtual ~Block() = default;
};
