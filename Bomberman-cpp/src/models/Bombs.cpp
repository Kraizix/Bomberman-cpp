#include "models/Bombs.h"
#include "models/Entity.h"
#include "models/Level.h"
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

void Bombs::Detonate(sf::Time _time, sf::Clock _clock, float _time2, std::vector<std::vector<Entity*>> map, int power, Player* player)
{
	if (_time.asSeconds() - _time2 >= 3 && player->m_NbOfBomb > 0)
	{

		_time = _clock.restart();
		Explosion(map, power);
		player->m_NbOfBomb += 1;
		this->SetPosition({ 1,1 });
	}
	return;
}

bool Explode_entity(std::vector<std::vector<Entity*>> map, Vec2f pos)
{
	Entity* square = map[pos.y][pos.x];
	EntityType type = square->GetEntityType();

	if (type == TBrick)
	{
		// Remplacer la case par une Grass entity
		return true;
	}
	else if (type == TWall) {
		// Passer
		return false;
	}
	else if (type == TPlayer) {
		// Detruire le joueur ? game over?
		return false;
	}
	else if (type == TEnemy) {
		// Détruire l'ennemi
		return false;
	}
	else {
		return false;
	}
}

void Bombs::Explosion(std::vector<std::vector<Entity*>> map, int power)
{
	Vec2f *Bomb_pos = this->GetPosition();
	// Conversion Vect2f
	Vec2f Bomb_pos_copy = *Bomb_pos;

	// Arrondir la pos de la bombe pour des calculs exacts
	Bomb_pos_copy.x = std::round(Bomb_pos_copy.x);
	Bomb_pos_copy.y = std::round(Bomb_pos_copy.y);

	Vec2f Vect_test = Bomb_pos_copy;
	Vect_test.x -= 1;
	if (Explode_entity(map, Vect_test))
	{
		delete map[Vect_test.y][Vect_test.x];
		map[Vect_test.y][Vect_test.x] = new Grass({ Vect_test.y, Vect_test.x });
	}
	Vect_test = Bomb_pos_copy;
	Vect_test.y += 1;
	if (Explode_entity(map, Vect_test))
	{
		delete map[Vect_test.y][Vect_test.x];
		map[Vect_test.y][Vect_test.x] = new Grass({ Vect_test.y, Vect_test.x });
	}
	Vect_test = Bomb_pos_copy;
	Vect_test.x += 1;
	if (Explode_entity(map, Vect_test))
	{
		delete map[Vect_test.y][Vect_test.x];
		map[Vect_test.y][Vect_test.x] = new Grass({ Vect_test.y, Vect_test.x });
	}
	Vect_test = Bomb_pos_copy;
	Vect_test.y -= 1;
	if (Explode_entity(map, Vect_test))
	{
		delete map[Vect_test.y][Vect_test.x];
		map[Vect_test.y][Vect_test.x] = new Grass({ Vect_test.y, Vect_test.x });
	}

	/*for (int index = Bomb_pos_copy.x; index > Bomb_pos_copy.x - power || Explode_entity(map, Bomb_pos_copy); index--)
	{
	}															 
	for (int index = Bomb_pos_copy.y; index < Bomb_pos_copy.y + power || Explode_entity(map, Bomb_pos_copy); index++)
	{}															 
	for (int index = Bomb_pos_copy.x; index < Bomb_pos_copy.x + power || Explode_entity(map, Bomb_pos_copy); index++)
	{}															 
	for (int index = Bomb_pos_copy.y; index > Bomb_pos_copy.y - power || Explode_entity(map, Bomb_pos_copy); index--)
	{}*/

	 /* while (Bomb_pos->y > Bomb_pos->y + power)
	{
		//check horizontal droit
	}
	while (Bomb_pos->x > Bomb_pos->x + power)
	{
		//check vertical bas
	}
	while (Bomb_pos->y > Bomb_pos->y - power)
	{
		//check horizontal gauche
	} */
}

