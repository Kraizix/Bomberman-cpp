#include "models/Level.h"
#include <iostream>
#include <fstream>
#include "models/Player.h"
#include <iostream>
#include <random>
#include <models/Enemy.h>
#include <managers/EnemyManager.h>

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

		file.close();
		m_emptyPos.erase(std::remove(m_emptyPos.begin(), m_emptyPos.end(), Vec2u{ 2,1 }), m_emptyPos.end());
		m_emptyPos.erase(std::remove(m_emptyPos.begin(), m_emptyPos.end(), Vec2u{ 1,2 }), m_emptyPos.end());
		GenerateBox();
		GenerateAI();
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

void Level::RenderLevel(sf::RenderTarget& _target, const Vec2f& _tileSize)
{
	for (auto& row: m_map)
	{
		for(auto& val : row)
		{
			val->SetSize(_tileSize);
			val->Render(_target);
		}
	}
	EnemyManager::GetInstance(m_map)->RenderEnemies(_target, _tileSize);
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
	std::uniform_int_distribution<int> dist(0, m_emptyPos.size() - 1);
	int i = dist(e);
	Vec2u p = m_emptyPos[i];
	std::cout << p.x << ", " << p.y << std::endl;
	m_emptyPos.erase(m_emptyPos.begin() + i);
	Trap* obs = new Trap(p);
	obs->Resize(Vec2f{ 64.0f, 64.0f });
	m_trap = obs;
	m_map[p.y][p.x] = obs;
}

void Level::UpdateTrap()
{
	m_trap->changeTexture();
	m_trap->Resize(Vec2f{ 64.0f, 64.0f });
}

void Level::GenerateAI()
{
	std::random_device r;
	std::default_random_engine e(r());
	int n = 3;
	while (n > 0)
	{
		std::uniform_int_distribution<int> dist(0, m_emptyPos.size() - 1);
		int i = dist(e);
		Vec2u p = m_emptyPos[i];
		std::cout << p.x << ", " << p.y << std::endl;
		m_emptyPos.erase(m_emptyPos.begin() + i);
		Enemy* enemy = new Enemy(p);
		enemy->Resize(Vec2f{ 64.0f, 64.0f });
		Grass* entity = new Grass(p);
		EnemyManager::GetInstance(m_map)->PushM_Enemy(enemy);
		entity->Resize(Vec2f{ 64.0f, 64.0f });
		m_map[p.y][p.x] = entity;
		n--;
	}
}

std::vector<std::vector<Entity*>>& Level::GetMap()
{
	return m_map;
}



void Level::MovePlayer(Vec2f _pos) {
	if (m_player == nullptr)
		return;
	//Vec2f npos = _player.GetPosition() + _pos;
	//bool c = false;
	//for (auto& it : m_entities) {
	//	if (_pos == it->GetPosition()) {
	//		c = true;
	//		return;
	//	}
	//}
	//if (c)
	//	return;
	m_player->SetPosition(_pos);
}

Player* Level::GetPlayer()
{
	return m_player;
}

