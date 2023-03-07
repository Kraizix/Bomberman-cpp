#include "models/Bombs.h"
#include "managers/WindowManager.h"
#include "models/Grass.h"
#include "models/Hatch.h"

#include <iostream>
#include <chrono>

Bombs::Bombs(Vec2f _pos, int _radius, std::vector<std::vector<Entity*>>& map, Player* _player) : m_map(map), m_player(_player)
{
	SetPosition(_pos);
	m_bombPosition = _pos;
	m_radius = _radius;
	SetSize({ 16.0f, 16.0f });
	SetSprite("B1");
	Resize({ 64.0f,64.0f });
	SetEntityType(TBomb);
	active = true;
}

void Bombs::Detonate(sf::Time _time, sf::Clock _clock, float _time2)
{
	if (active)
	{
		if (_time.asSeconds() - _time2 >= 3)
		{
			_time = _clock.restart();
			if ((round(m_player->GetPosition()->x) >= GetPosition()->x - 1 && round(m_player->GetPosition()->x) <= GetPosition()->x + 1) && (round(m_player->GetPosition()->y) >= GetPosition()->y - 1 && round(m_player->GetPosition()->y) <= GetPosition()->y + 1))
			{
				WindowManager::GetInstance()->GetWindow()->close();
			}
			Destroy_walls();
			//TODO : Detruire les ennemis
			active = false;
		}
	}
}

void Bombs::Destroy_walls()
{
	for(int i =-m_radius; i <= m_radius; i++)
	{
		if (GetPosition()->x+ i >m_map[0].size() || GetPosition()->x + i < 0){
			continue;
		}
		Entity* e = m_map[GetPosition()->y][GetPosition()->x + i];
		if(e->GetEntityType() == TBrick)
		{
			Grass* entity = new Grass({ GetPosition()->x+ i, GetPosition()->y });
			m_map[GetPosition()->y][GetPosition()->x + i] = entity;
			entity->Resize(Vec2f{ 64.0f, 64.0f });
		}
		if(e->GetEntityType() == THatch)
		{
			((Hatch*)e)->changeTexture();
		}
	}
	for (int i = -m_radius; i <= m_radius; i++)
	{
		if (GetPosition()->y+ i > m_map[0].size() || GetPosition()->y + i <0) {
			continue;
		}
		Entity* e = m_map[GetPosition()->y + i][GetPosition()->x];
		if (e->GetEntityType() == TBrick)
		{
			Grass* entity = new Grass({ GetPosition()->x, GetPosition()->y+i });
			m_map[GetPosition()->y+i][GetPosition()->x] = entity;
			entity->Resize(Vec2f{ 64.0f, 64.0f });
		}
		if (e->GetEntityType() == THatch)
		{
			((Hatch*)e)->changeTexture();
		}
	}
}


void Bombs::SetRadius(int _value)
{
	m_radius += _value;
}
