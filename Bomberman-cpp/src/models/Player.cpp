#include "models/Player.h"
#include <iostream>

Player::Player(const Vec2f& _position)
{
	SetPosition(_position);
	m_actualPosition = _position;
	m_speed = 2.0f; // in pixel per second
	m_speedCoeficient = 1.0f;
	m_NbOfBomb = 1;
	SetPosition({1,1});
	SetSize({ 16.0f, 16.0f });
	SetSprite("F1");
	Resize({ 64.0f,64.0f });
	SetEntityType(TPlayer);
}

Vec2f Player::Move(Vec2f move)
{

	m_actualPosition = *GetPosition();
	move.x *= (m_speed * m_speedCoeficient) / RATE;
	move.y *= (m_speed * m_speedCoeficient) / RATE;
	m_actualPosition.Add(move);
	return m_actualPosition;
}

void Player::placeBomb()
{
}
