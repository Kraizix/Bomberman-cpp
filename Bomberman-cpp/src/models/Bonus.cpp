#include "models/Entity.h"
#include "models/Bonus.h"

Bonus::Bonus(BonusType _bonusType, Vec2f _pos)
{
	SetPosition(_pos);
	m_bonusType = _bonusType;
	SetSize({ 16.0f, 16.0f });
	SetSprite("Speed");
	Resize({ 64.0f,64.0f });
	SetEntityType(TBonus);
}

void Bonus::PowerUp(Player* _player, Bombs* _bombs)
{
	switch (m_bonusType) 
	{
	case SpeedUp:
		_player->SetspeedCoeficient(0.05);
		SetPosition({ -1 , -1 });
		break;
	case ExplosionUp:
		_bombs->SetRadius(1);
		break;
	case CapacityUp:
		_player->SetNbOfBomb(1);
		break;
	}
}

void Bonus::spawnBonus()
{
}
