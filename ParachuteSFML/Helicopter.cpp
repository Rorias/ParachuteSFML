#include "Helicopter.h"

Helicopter::Helicopter()
{
	std::string s = "assets/helicopter.png";

	if (!texture.loadFromFile(s))
	{
		return;
	};

	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.5f);

	xOffset = (sprite.getLocalBounds().width * sprite.getScale().x) / 2;
	yOffset = (sprite.getLocalBounds().height * sprite.getScale().y) / 2;

	minBound = xOffset;
	maxBound = 800 - xOffset;

	sprite.setOrigin(xOffset / sprite.getScale().x, yOffset / sprite.getScale().y);
	sprite.setPosition(xOffset, 0 + yOffset);
}

Helicopter::~Helicopter() {}

sf::Sprite Helicopter::Display()
{
	return sprite;
}

void Helicopter::Move()
{
	x = sprite.getPosition().x;
	y = sprite.getPosition().y;

	sprite.move(speed, 0);

	if (sprite.getPosition().x >= maxBound || sprite.getPosition().x <= minBound)
	{
		speed = -speed;
		sprite.scale(-1, 1);
	}
}

void Helicopter::Timer()
{
	dropTime -= 0.008334f;

	if (dropTime <= 0)
	{
		dropTime = maxDropTime;
		maxDropTime -= 0.25f;
		dropping = true;
	}
}
