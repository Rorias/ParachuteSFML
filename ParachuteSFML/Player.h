#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	sf::Sprite Display();
	void Move();
	bool Collide(Entity* p);

private:
	float vel = 0.0f;
	float accel = 0.02f;
	float decel = 0.04f;
};

