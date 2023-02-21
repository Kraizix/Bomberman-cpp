#include "models/Level.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <random>

Level::~Level()
{
	for (auto& it : m_entities)
	{
		if (it != nullptr)
			delete it;
	}
	m_entities.clear();

	for (auto& it : m_map)
	{
		it.second.clear();
	}
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
			std::unordered_map<unsigned int, Entity*> rowTiles;
			std::vector<Entity*> rowEntities;
			

			for (auto& c : line)
			{
				Vec2u position{ column, row };

				switch (c)
				{
				case '1':
				{
					Grass* entity = new Grass(position);
					m_entities.emplace_back(entity);
					rowTiles.insert({ column, entity });
					rowEntities.emplace_back(entity);
					entity->Resize(Vec2f{ 64.0f, 64.0f });
					emptyPos.push_back(position);
					break;
				}
				case '2':
				{
					Border* entity = new Border(position);
					m_entities.emplace_back(entity);
					rowTiles.insert({ column, entity });
					rowEntities.emplace_back(entity);
					entity->Resize(Vec2f{ 64.0f, 64.0f});
					break;
				}
				default:
				{
					Grass* entity = new Grass(position);
					m_entities.emplace_back(entity);
					rowTiles.insert({ column, entity });
					rowEntities.emplace_back(entity);
					entity->Resize(Vec2f{ 64.0f, 64.0f });
				}
				}

				column++;
			}
			map.emplace_back(rowEntities);
			m_map.insert({ row, rowTiles });
			row++;
		}

		file.close();
		GenerateBox(emptyPos);
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
	/*for (auto& it : m_entities)
	{
		it->SetSize(_tileSize);
		it->Render(_target);
	}*/
	for (auto& row: map)
	{
		for(auto& val : row)
		{
			val->SetSize(_tileSize);
			val->Render(_target);
		}
	}
}

void Level::GenerateBox(std::vector<Vec2u> pos)
{
	std::random_device r;
	std::default_random_engine e(r());
	int n = 100;
	while(n > 0)
	{
		std::uniform_int_distribution<int> dist(0, pos.size() - 1);
		Vec2u p = pos[dist(e)];
		std::cout << p.x << ", " << p.y << std::endl;
		pos.erase(pos.begin() + dist(e));
		Block* obs = new Block(p);
		obs->Resize(Vec2f{ 64.0f, 64.0f });
		map[p.y][p.x] = obs;
		n--;
	}
}


/*
void Level::MovePlayer(Vec2f _pos) {
	if (m_player == nullptr)
		return;
	Vec2f npos = m_player->GetPosition() + _pos;
	bool c = false;
	for (auto& it : m_entities) {
		if (npos == it->GetPosition()) {
			c = true;
			return;
		}
	}
	if (c)
		return;
	m_player->SetPosition(npos);
}
*/
