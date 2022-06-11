#pragma once
#include "Position.h"
#include "Keys.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Player : public Position
{
public:
	Player();
	~Player();

	sf::Sprite Display();
	void Move();
	bool Collide(Position p);

private:
	sf::Texture texture;
	sf::Sprite playerSprite;
	int xOffset;
	int yOffset;
};

