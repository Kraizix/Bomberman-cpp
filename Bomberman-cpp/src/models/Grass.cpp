#include "models/Grass.h"

Grass::Grass(const Vec2f& _position)
{
	SetPosition(_position);
	SetSprite("grass");
	SetEntityType(TGrass);
}
