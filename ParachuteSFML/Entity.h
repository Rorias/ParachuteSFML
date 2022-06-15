#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	float x = 0.0f;
	float y = 0.0f;
	float xOffset = 0.0f;
	float yOffset = 0.0f;

protected:
	sf::Texture texture;
	sf::Sprite sprite;
	float minBound = 0.0f;
	float maxBound = 800.0f;
};

