#include "models/Bombs.h"

#include <iostream>
#include <chrono>

Bombs::Bombs(Vec2f _pos, int _radius)
{
	SetPosition(_pos);
	m_bombPosition = _pos;
	m_radius = _radius;
	SetSize({ 16.0f, 16.0f });
	SetSprite("B1");
	Resize({ 64.0f,64.0f });
	SetEntityType(TBomb);
}

void Bombs::Detonate(sf::Time _time, sf::Clock _clock, float _time2)
{
	if (_time.asSeconds() - _time2 >= 3)
	{
		_time = _clock.restart();
		this->SetPosition({ -1,-1 });
	}
	return;
}
