#include "models/Player.h"
#include "models/Bombs.h"
#include <iostream>

Player::Player(const Vec2f& _position)
{
	SetPosition(_position);
	m_actualPosition = _position;
	m_speed = 2.0f;
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
	move.x *= (m_speed * m_speedCoeficient)/RATE;
	move.y *= (m_speed * m_speedCoeficient)/RATE;
	m_actualPosition.Add(move);
	return m_actualPosition;
}

void Player::SetspeedCoeficient(float _value)
{
	m_speedCoeficient += _value;
}

void Player::SetNbOfBomb(int _value)
{
	m_NbOfBomb +=  _value;
}

float Player::GetSpeed()
{
	return m_speedCoeficient;
}

void Player::SetDeltaT(float* _deltaT)
{
	deltaT = _deltaT;
}
