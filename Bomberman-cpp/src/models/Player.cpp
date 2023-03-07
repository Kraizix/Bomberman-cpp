#include "models/Player.h"
#include "models/Bombs.h"
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
	std::cout << *deltaT << std::endl;
	m_actualPosition = *GetPosition();
	move.x *= (m_speed * m_speedCoeficient)*8* *deltaT;
	move.y *= (m_speed * m_speedCoeficient)*8 * *deltaT;

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
