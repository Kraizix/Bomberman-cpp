#pragma once
#include "models/Entity.h"

class Grass : public Entity
{
public:
	Grass(const Vec2f& _position);
	virtual ~Grass() = default;
};
