#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "Entity.h"
#include "Block.h"
#include "Grass.h"
#include "Border.h"
#include "Obstacle.h"

class Level
{
public:
	Level() = default;
	virtual ~Level();
	bool LoadLevel(const std::string& _fileName);
	Vec2f GetSize(const Vec2f& _tileSize);
	void RenderLevel(sf::RenderTarget& _target, const Vec2f& _tileSize);
	void MovePlayer(Vec2f _pos);
	void GenerateBox(std::vector<Vec2u> pos);

private:
	std::vector<Entity*> m_entities;
	std::vector<std::vector<Entity*>> m_map;
};
