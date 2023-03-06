#pragma once
#include "models/Entity.h"

class Hatch : public Entity
{
public:
	Hatch(const Vec2f& _position);
	virtual ~Hatch() = default;
	void changeTexture();
	int* GetIndex();
private:
	std::vector<std::string> m_textures;
	int index = -1;
};