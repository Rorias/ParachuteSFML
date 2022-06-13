#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity
{
public:
	float x;
	float y;

protected:
	sf::Texture texture;
	sf::Sprite sprite;
	float xOffset;
	float yOffset;
	float minBound;
	float maxBound;
};

