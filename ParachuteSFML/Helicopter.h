#pragma once
#include "Entity.h"
#include "Parachutist.h"

class Helicopter : public Entity
{
public:
	Helicopter();
	~Helicopter();

	sf::Sprite Display();
	void Move();
	void Timer();

	float speed = 2.0f;
	bool dropping = false;

private:
	float dropTime = 1.0f;
	float maxDropTime = 6.0f;
};

