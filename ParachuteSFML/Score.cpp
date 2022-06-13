#include "Score.h"

Score::Score()
{
	std::string s = "assets/arial.ttf";

	if (!font.loadFromFile(s))
	{
		return;
	}

	text.setFont(font);
	text.setString("Score: ");
	text.setCharacterSize(32);
	text.setFillColor(sf::Color::Black);
	text.setPosition(4, 800);

	std::string s2 = "assets/sharkcount.png";

	if (!texture.loadFromFile(s2))
	{
		return;
	};

	sprite1.setScale(0.4f, 0.4f);
	sprite2.setScale(0.4f, 0.4f);
	sprite3.setScale(0.4f, 0.4f);

	sprite1.setPosition(750, 800);
	sprite2.setPosition(695, 800);
	sprite3.setPosition(640, 800);
}

Score::~Score() {}

sf::Text Score::Display()
{
	return text;
}

void Score::Increment()
{
	score++;
	std::string s = std::to_string(score);
	text.setString("Score: " + s);
}

void Score::Miss()
{
	if (miss < 3)
	{
		miss++;

		switch (miss)
		{
			case 1:
				sprite1.setTexture(texture);
				break;
			case 2:
				sprite2.setTexture(texture);
				break;
			case 3:
				sprite3.setTexture(texture);
				break;
		}
	}
}

void Score::CheckGoal()
{
	if (miss >= 3) {}

	if (score >= 15) {}
}
