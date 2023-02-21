#pragma once
#include "models/Entity.h"

class Border : public Entity
{
public:
	Border(const Vec2f& _position);
	virtual ~Border() = default;
};
