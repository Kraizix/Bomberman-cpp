#pragma once

#define RATE 30

#include "models/Entity.h"


class Player : public Entity
{
	public:
		Player(const Vec2f& _position);
		virtual ~Player() = default;
		Vec2f Move(Vec2f);
		void placeBomb();

	private:
		Vec2f m_actualPosition;
		float m_speed;
		float m_speedCoeficient;
		int m_NbOfBomb;
};

