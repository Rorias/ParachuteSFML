#include "Parachutist.h"

Parachutist::Parachutist(float x)
{
	std::string s = "assets/parachutistfalling.png";

	if (!texture.loadFromFile(s))
	{
		return;
	};

	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.5f);

	xOffset = (sprite.getLocalBounds().width * sprite.getScale().x) / 2;
	yOffset = (sprite.getLocalBounds().height * sprite.getScale().y) / 2;

	sprite.setOrigin(xOffset / sprite.getScale().x, yOffset / sprite.getScale().y);

	sprite.setPosition(x, 100 + yOffset);
	
}

Parachutist::~Parachutist() {}

sf::Sprite Parachutist::Display()
{
	return sprite;
}

void Parachutist::Move()
{
	if (sprite.getPosition().y <= 0)
	{

	}
}

void Parachutist::Destroy()
{
	delete this;
}
