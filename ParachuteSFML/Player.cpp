#include "Player.h"

Player::Player()
{
	std::string s = "assets/player.png";

	if (!texture.loadFromFile(s))
	{
		return;
	};

	playerSprite.setTexture(texture);
	playerSprite.setScale(0.5f, 0.5f);

	xOffset = playerSprite.getLocalBounds().width / 2;
	yOffset = playerSprite.getLocalBounds().height / 2;

	playerSprite.setOrigin(xOffset, yOffset);
	playerSprite.setPosition(xOffset, 663 + yOffset);
}
Player::~Player() {}

sf::Sprite Player::Display()
{
	return playerSprite;
}

void Player::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		playerSprite.move(-0.1f, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		playerSprite.move(0.1f, 0);
	}
}

bool Player::Collide(Position p)
{
	return true;
}
