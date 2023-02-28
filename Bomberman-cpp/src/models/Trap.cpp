#include "models/Trap.h"


Trap::Trap(const Vec2f& _position)
{
	SetPosition(_position);
	SetSprite("brick");
	m_textures.emplace_back("c_trap");
	m_textures.emplace_back("o_trap");
}

void Trap::changeTexture()
{
	index++;
	SetSprite(m_textures[index]);
}

