#pragma once
#include <SFML/Graphics.hpp>

class Score
{
public:
	Score();
	~Score();

	sf::Text Display();
	void Increment();
	void Miss();
	void CheckGoal();

	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite sprite3;

	bool gameOver = false;

private:
	sf::Font font;
	sf::Text text;
	sf::Texture texture;

	int score = 0;
	int miss = 0;
};

