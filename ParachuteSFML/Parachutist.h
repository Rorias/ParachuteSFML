#pragma once
#include "Entity.h"

class Parachutist : public Entity
{
public:
	Parachutist(float x);
	~Parachutist();

	sf::Sprite Display();
	void Move();
	void Destroy();

private:
	Entity* entity;
};

