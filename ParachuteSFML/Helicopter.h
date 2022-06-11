#pragma once
#include "Position.h"
#include <SFML/Graphics.hpp>

class Helicopter : public Position
{
public:
	Helicopter();
	~Helicopter();

	void Display();
	void Move();
	void Drop(long t);

private:
	sf::Texture texture;
	sf::Sprite heliSprite;
	int xOffset;
	int yOffset;
};

