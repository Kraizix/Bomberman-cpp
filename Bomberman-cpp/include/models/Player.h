#pragma once

#define RATE 60

#include "models/Entity.h"


class Player : public Entity
{
	public:
		Player(const Vec2f& _position);
		virtual ~Player() = default;
		Vec2f Move(Vec2f);
		void SetspeedCoeficient(float _value);
		void SetNbOfBomb(int _value);
		float GetSpeed();
		void SetDeltaT(float* _deltaT);

	private:
		float* deltaT;
		Vec2f m_actualPosition;
		float m_speed;
		float m_speedCoeficient;
		int m_NbOfBomb;
};

