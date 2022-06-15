#include "Parachutist.h"

Parachutist::Parachutist(float x, float speed)
{
	std::string s = "assets/parachutistfalling.png";
	std::string s2 = "assets/parachutist.png";

	if (!texture.loadFromFile(s))
	{
		return;
	}

	if (!texture2.loadFromFile(s2))
	{
		return;
	}

	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.5f);

	xOffset = (sprite.getLocalBounds().width * sprite.getScale().x) / 2;
	yOffset = (sprite.getLocalBounds().height * sprite.getScale().y) / 2;

	minBound = xOffset;
	maxBound = 800 - xOffset;

	sprite.setOrigin(xOffset / sprite.getScale().x, yOffset / sprite.getScale().y);

	sprite.setPosition(x, 100 + yOffset);

	xvel = speed;
	yvel = 0.5f;
}

Parachutist::~Parachutist() {}

sf::Sprite Parachutist::Display()
{
	return sprite;
}

bool Parachutist::Move()
{
	x = sprite.getPosition().x;
	y = sprite.getPosition().y;

	if (!maxDropReached && yvel < 3.0f)
	{
		yvel = yvel + accel;
	}
	else if (yvel >= 3.0f)
	{
		maxDropReached = true;
		yvel = 1.25f;

		sprite.setTexture(texture2, true);

		xOffset = (sprite.getLocalBounds().width * sprite.getScale().x) / 2;
		yOffset = (sprite.getLocalBounds().height * sprite.getScale().y) / 2;

		minBound = xOffset;
		maxBound = 800 - xOffset;

		sprite.setOrigin(xOffset / sprite.getScale().x, yOffset / sprite.getScale().y);
	}

	if (maxDropReached)
	{
		//rotate between -30, 30
		if (rotate < -30 || rotate>30)
		{
			rotdir = -rotdir;
		}
		rotate += rotdir;

		//move between -5, 5
		if (xwiggle < -5 || xwiggle>5)
		{
			xwiggledir = -xwiggledir;
		}
		xwiggle += xwiggledir;

		sprite.setRotation(rotate);
		sprite.move(xwiggle, 0);
	}

	if (xvel > 0.02f)
	{
		xvel = xvel - decel;
	}
	else if (xvel < -0.02)
	{
		xvel = xvel + decel;
	}
	else
	{
		xvel = 0;
	}

	if (x >= maxBound || x <= minBound)
	{
		xvel = -xvel;
	}

	sprite.move(xvel, yvel);

	if (y >= 836 + yOffset)
	{
		return true;
	}

	return false;
}

void Parachutist::Destroy()
{
	delete this;
}
