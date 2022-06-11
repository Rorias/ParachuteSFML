#include "Main.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	Player* p = new Player();

	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML Works!");

	//sf::Texture texture;
	//std::string s = "assets/parachutist.png";

	//if (!texture.loadFromFile(s))
	//{
	//	std::cout << "Couldnt find file in " + s;
	//	return 0;
	//};

	//sf::Sprite paraSprite;
	//paraSprite.setTexture(texture);
	//paraSprite.setScale(0.5f, 0.5f);
	//paraSprite.setOrigin(65.f, 65.f);
	//paraSprite.setPosition(65.f, 65.f);
	//paraSprite.setRotation(45.f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) { window.close(); }
		}

		window.clear(sf::Color::White);
		p->Move();
		window.draw(p->Display());
		window.display();
	}
}