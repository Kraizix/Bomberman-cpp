#pragma once

#include "models/Entity.h"
#include "models/Player.h"

class Bombs : public Entity
{
	public :
		Bombs(Vec2f _pos, int _radius, std::vector<std::vector<Entity*>>& map, Player* _player);
		virtual ~Bombs() = default;
		void Detonate(sf::Time _time, sf::Clock _clock, float _time2);
		void Destroy_walls();
		void SetRadius(int _value);
		bool active;

	private:
		std::vector<std::vector<Entity*>>& m_map;
		Player* m_player;
		int m_radius;
		Vec2f m_bombPosition;
};

