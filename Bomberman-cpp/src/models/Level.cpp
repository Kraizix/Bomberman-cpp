#include "models/Level.h"
#include <iostream>
#include <fstream>

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

		while (std::getline(file, line))
		{
			column = 0;
			std::unordered_map<unsigned int, Entity*> rowTiles;

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
					break;
				}
				default:
				{
					Block* entity = new Block(position);
					m_entities.emplace_back(entity);
					rowTiles.insert({ column, entity });
				}
				}

				column++;
			}

			m_map.insert({ row, rowTiles });
			row++;
		}

		file.close();
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
	for (auto& it : m_entities)
	{
		it->SetSize(_tileSize);
		it->Render(_target);
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
