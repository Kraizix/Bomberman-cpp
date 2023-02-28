#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "utils/Vector2.h"

enum EntityType
{
	TBrick,
	TWall,
	TGrass,
	TPlayer,
	TEnemy,
	TBonus,
	THatch
};

class Entity
{
public:
	Entity();
	virtual ~Entity();
	void Render(sf::RenderTarget& _target);
	void SetSprite(const std::string& _assetId, const Vec2f& _position = { 0.f, 0.f }, const Vec2f& _size = { 0.f, 0.f });
	void SetPosition(const Vec2f& _position);
	Vec2f* GetPosition();
	void SetSize(const Vec2f& _size);
	Vec2f* GetSize();
	bool IsDestroyable();
	EntityType GetEntityType();
	void SetEntityType(EntityType);
	void Resize(const Vec2f& _size);

private:
	sf::Sprite* m_sprite;
	Vec2f m_spriteSize;
	Vec2f m_position;
	Vec2f m_size;
	EntityType m_EntityType;
protected:
	bool m_destroyable;
};
