#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "Entity.h"
#include "Block.h"
#include "Grass.h"
#include "Player.h"

class Level
{
public:
	Level() = default;
	virtual ~Level();
	bool LoadLevel(const std::string& _fileName);
	Vec2f GetSize(const Vec2f& _tileSize);
	void RenderLevel(sf::RenderTarget& _target, const Vec2f& _tileSize);
	void MovePlayer(Vec2f _pos);
	Player* GetPlayer();

private:
	Player* m_player;
	std::vector<Entity*> m_entities;
	std::unordered_map<unsigned int, std::unordered_map<unsigned int, Entity*>> m_map;
};
