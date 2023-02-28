#include "models/Level.h"
#include <iostream>
#include <fstream>
#include "models/Player.h"
#include <iostream>
#include <random>
#include <cmath>
#include <models/Bombs.h>

Level::~Level()
{
	for(auto& it : m_map)
	{
		for (auto& v : it)
		{
			if (v != nullptr)
				delete v;
		}
		it.clear();
	}
	m_emptyPos.clear();
	m_map.clear();
}

bool Level::LoadLevel(const std::string& _fileName)
{
	std::ifstream file(_fileName, std::ios_base::in);
	if (file.is_open())
	{
		std::cout << ">> File level is open" << std::endl;
		std::string line;
		unsigned int row = 0;
		unsigned int column = 0;
		float tileSize = 64.f;
		std::vector<Vec2u> emptyPos;

		while (std::getline(file, line))
		{
			column = 0;
			std::vector<Entity*> rowEntities;

			for (auto& c : line)
			{
				Vec2u position{ column, row };

				switch (c)
				{
				case '1':
				{
					Grass* entity = new Grass(position);
					rowEntities.emplace_back(entity);
					m_emptyPos.push_back(position);
					entity->Resize(Vec2f{ 64.0f, 64.0f });
					break;
				}
				case '7':
				{
					Grass* entity = new Grass(position);
					rowEntities.emplace_back(entity);
					entity->Resize(Vec2f{ 64.0f, 64.0f });
					break;
				}
				case '2':
				{
					Wall* entity = new Wall(position);
					rowEntities.emplace_back(entity);
					entity->Resize(Vec2f{ 64.0f, 64.0f});
					break;
				}
				default:
				{
					Grass* entity = new Grass(position);
					rowEntities.emplace_back(entity);
					entity->Resize(Vec2f{ 64.0f, 64.0f });
				}
				}

				column++;
			}

			//m_map.insert({ row, rowTiles });
			m_map.emplace_back(rowEntities);
			row++;
		}

		m_player = new Player({ 1,1 });
		m_bomb = new Bombs({ -1,-1 }, 1);

		file.close();
		m_emptyPos.erase(std::remove(m_emptyPos.begin(), m_emptyPos.end(), Vec2u{ 2,1 }), m_emptyPos.end());
		m_emptyPos.erase(std::remove(m_emptyPos.begin(), m_emptyPos.end(), Vec2u{ 1,2 }), m_emptyPos.end());
		GenerateBox();
		return true;
	}
	else
	{
		std::cout << ">> File level cannot be open !" << std::endl;
		return false;
	}
}

Vec2f Level::GetSize(const Vec2f& _tileSize)
{
	if (!m_map.empty())
	{
		auto it = m_map.at(0);
		if (!it.empty())
		{
			return Vec2f(it.size(), m_map.size()) * _tileSize;
		}
	}

	return Vec2f(0.f, 0.f);
}

void Level::RenderLevel(sf::RenderTarget& _target, const Vec2f& _tileSize, bool& _placeBomb)
{

	if (_placeBomb)
	{
		m_bomb->SetPosition(m_player->GetPosition());
		_placeBomb = false;
	}

	for (auto& row: m_map)
	{
		for(auto& val : row)
		{
			val->SetSize(_tileSize);
			val->Render(_target);
		}
	}

	m_bomb->SetSize(_tileSize);
	m_bomb->Render(_target);

	m_player->SetSize(_tileSize);
	m_player->Render(_target);

}

void Level::GenerateBox()
{
	std::random_device r;
	std::default_random_engine e(r());
	int n = 40;
	while(n > 0)
	{
		std::uniform_int_distribution<int> dist(0, m_emptyPos.size() - 1);
		int i = dist(e);
		Vec2u p = m_emptyPos[i];
		std::cout << p.x << ", " << p.y << std::endl;
		m_emptyPos.erase(m_emptyPos.begin() + i);
		Brick* obs = new Brick(p);
		obs->Resize(Vec2f{ 64.0f, 64.0f });
		m_map[p.y][p.x] = obs;
		n--;
	}
}

EntityType Level::GetCaseType(Vec2f _pos, Vec2f _direction)
{
	float x = 0.0f;
	float y = 0.0f;

	if (_direction.x == 1)
	{
		x = ceil(_pos.x);
	}
	else if(_direction.x == -1)
	{
		x = floor(_pos.x);
	}
	else
	{
		x = round(_pos.x);
	}
	
	if (_direction.y == 1)
	{
		y = ceil(_pos.y);
	}
	else if (_direction.y == -1)
	{
		y = floor(_pos.y);
	}
	else
	{
		y = round(_pos.y);
	}

	for (auto& vec : m_map) 
	{
		for (auto& ent : vec)
		{
			if(ent->GetPosition().x == x && ent->GetPosition().y == y)
				return ent->GetEntityType();
		}
	}
	return TGrass;
}


void Level::MovePlayer(Vec2f _pos, Vec2f _direction) {
	if (m_player == nullptr || GetCaseType(_pos, _direction) == TBrick || GetCaseType(_pos, _direction) == TWall)
		return;

	std::cout << "floor : " << floor(_pos.x) << " " << floor(_pos.y) << std::endl;

	std::cout << "ceil : " << ceil(_pos.x) << " " << ceil(_pos.y) << std::endl;

	std::cout << "round : " << round(_pos.x) << " " << round(_pos.y) << std::endl;

	m_player->SetPosition(_pos);
}

Player* Level::GetPlayer()
{
	return m_player;
}

Bombs* Level::GetBombs()
{
	return m_bomb;
}
