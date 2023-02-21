#pragma once
#include "models/Entity.h"

class Wall : public Entity
{
public:
	Wall(const Vec2f& _position);
	virtual ~Wall() = default;
};
