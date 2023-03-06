#pragma once

#include "models/Entity.h"

class Bombs : public Entity
{
	public :
		Bombs(Vec2f _pos, int _radius);
		virtual ~Bombs() = default;
		void Detonate(sf::Time _time, sf::Clock _clock, float _time2);
		void SetRadius(int _value);

	private:
		int m_radius;
		Vec2f m_bombPosition;
};

