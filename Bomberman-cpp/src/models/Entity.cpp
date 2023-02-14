#include "models/Entity.h"
#include "managers/AssetManager.h"
#include "managers/WindowManager.h"

Entity::Entity()
{
	m_sprite = nullptr;
	m_spriteSize = { 0.f, 0.f };
	m_position = { 0.f, 0.f };
}

Entity::~Entity()
{
	if (m_sprite != nullptr)
	{
		delete m_sprite;
	}
}

void Entity::Render(sf::RenderTarget& _target)
{
	if (m_sprite != nullptr)
	{
		Vec2f position = GetPosition();
		Vec2f size = GetSize();
		m_sprite->setPosition(position * size);
		_target.draw(*m_sprite);
	}
}

void Entity::SetSprite(const std::string& _assetId, const Vec2f& _position, const Vec2f& _size)
{
	sf::Texture* texture = AssetManager::GetInstance()->GetTexture(_assetId);

	if (texture != nullptr)
	{
		if (m_sprite != nullptr)
		{
			delete m_sprite;
		}

		m_sprite = new sf::Sprite();
		m_sprite->setTexture(*texture);

		if (_size.x > 0 && _size.y > 0)
		{
			m_sprite->setTextureRect(sf::IntRect(_position.x, _position.y, _size.x, _size.y));
			m_spriteSize = _size;
		}
		else
		{
			m_spriteSize = { (float)texture->getSize().x, (float)texture->getSize().y };
		}
	}
}

void Entity::SetPosition(const Vec2f& _position)
{
	m_position = _position;
}

Vec2f Entity::GetPosition()
{
	return m_position;
}

void Entity::SetSize(const Vec2f& _size)
{
	m_size = _size;
}

Vec2f Entity::GetSize()
{
	return m_size;
}
