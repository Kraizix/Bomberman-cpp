#pragma once

#include <iostream>
#include "models/Entity.h"
#include "Player.h"
#include "Bombs.h"

enum BonusType
{
	SpeedUp,
	ExplosionUp,
	CapacityUp
};

class Bonus : public Entity
{
	public:
		Bonus(BonusType _bonusType, Vec2f _pos);
		void PowerUp(Player* _player, Bombs* _bombs);
		void spawnBonus();
		~Bonus() = default;

	private:
		BonusType m_bonusType;

};

