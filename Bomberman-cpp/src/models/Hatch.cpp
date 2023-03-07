#include "models/Hatch.h"

// TODO : Faire ouvrir la trappe quand tous les ennemis sont morts
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
	index = 1;
	SetSprite(m_textures[index]);
	Resize({ 64,64 });
}

int* Hatch::GetIndex()
{
	return &index;
}
