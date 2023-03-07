#pragma once

#include "models/Entity.h"

class Bombs : public Entity
{
	public :
		Bombs(Vec2f _pos, int _radius);
		virtual ~Bombs() = default;
		void Detonate(sf::Time _time, sf::Clock _clock, float _time2, std::vector<std::vector<Entity*>> map, int power, bool &placebomb);
		void Explosion(std::vector<std::vector<Entity*>> map, int power);

	private:
		int m_radius;
		Vec2f m_bombPosition;
};

