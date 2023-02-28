#pragma once
#include "models/Entity.h"

class Trap : public Entity
{
public:
	Trap(const Vec2f& _position);
	virtual ~Trap() = default;
	void changeTexture();
private:
	std::vector<std::string> m_textures;
	int index = -1;
};