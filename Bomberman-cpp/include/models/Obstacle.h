#pragma once
#include "models/Entity.h"

class Obstacle : public Entity
{
public:
	Obstacle(const Vec2f& _position);
	virtual ~Obstacle() = default;
};
