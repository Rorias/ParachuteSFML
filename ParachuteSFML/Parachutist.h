#pragma once
#include "Entity.h"

class Parachutist : public Entity
{
public:
	Parachutist(float x, float speed);
	~Parachutist();

	sf::Sprite Display();
	bool Move();
	void Destroy();

private:
	sf::Texture texture2;
	bool maxDropReached = false;
	float xvel = 2.0f;
	float yvel = 0.5f;
	float accel = 0.02f;
	float decel = 0.01f;
	float rotate = 30;
	float rotdir = 0.6f;
	float xwiggle = 0;
	float xwiggledir = 0.1f;
};

