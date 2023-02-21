#pragma once
#include "models/Entity.h"

class Brick : public Entity
{
public:
	Brick(const Vec2f& _position);
	virtual ~Brick() = default;
};
