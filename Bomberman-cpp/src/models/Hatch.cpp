#include "models/Hatch.h"


Hatch::Hatch(const Vec2f& _position)
{
	SetPosition(_position);
	SetSprite("brick");
	SetEntityType(THatch);
	m_textures.emplace_back("c_trap");
	m_textures.emplace_back("o_trap");
}

void Hatch::changeTexture()
{
	index++;
	SetSprite(m_textures[index]);
}

int* Hatch::GetIndex()
{
	return &index;
}
