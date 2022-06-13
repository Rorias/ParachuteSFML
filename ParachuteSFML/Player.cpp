#include "Player.h"

Player::Player()
{
	std::string s = "assets/player.png";

	if (!texture.loadFromFile(s))
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
	sprite.setPosition(600 + xOffset, 800 - yOffset);
}
Player::~Player() {}

sf::Sprite Player::Display()
{
	return sprite;
}

void Player::Move()
{
	x = sprite.getPosition().x;
	y = sprite.getPosition().y;

	bool left = false;
	bool right = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		left = true;
		if (-3 < vel) { vel = vel - accel; }
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		right = true;
		if (vel < 3) { vel = vel + accel; }
	}

	if (!left && !right)
	{
		if (vel > 0.02f)
		{
			vel = vel - decel;
		}
		else if (vel < -0.02)
		{
			vel = vel + decel;
		}
		else
		{
			vel = 0;
		}
	}

	if (sprite.getPosition().x < minBound)
	{
		sprite.setPosition(minBound, sprite.getPosition().y);
		vel = 0;
	}

	if (sprite.getPosition().x > maxBound)
	{
		sprite.setPosition(maxBound, sprite.getPosition().y);
		vel = 0;
	}

	sprite.move(vel, 0);
}

bool Player::Collide(Entity* p)
{
	if ((p->x - p->xOffset < x + xOffset && p->x + p->xOffset > x) &&
		(p->y + p->yOffset > y + (yOffset / 4) && p->y - p->yOffset < y + yOffset))
	{
		return true;
	}

	return false;
}
