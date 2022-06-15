#include "Main.h"

const static int poolSize = 4;
static Parachutist* enemyPool[4];

int main()
{
	Player* p = new Player();
	Helicopter* h = new Helicopter();
	Score* s = new Score();

	sf::RenderWindow window(sf::VideoMode(800, 836), "Game&Watch Parachuters");

	window.setFramerateLimit(120);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) { window.close(); }
		}

		window.clear(sf::Color::White);

		if (!s->gameOver)
		{
			h->Timer();
			if (h->dropping)
			{
				Main::AddEnemy(new Parachutist(h->x, h->speed));
				h->dropping = false;
			}

			p->Move();
			h->Move();

			for (int i = 0; i < poolSize; i++)
			{
				if (enemyPool[i] != NULL)
				{
					window.draw(enemyPool[i]->Display());

					if (p->Collide(enemyPool[i]))
					{
						s->Increment();
						Main::RemoveEnemy(enemyPool[i]);
						break;
					}

					if (enemyPool[i]->Move())
					{
						s->Miss();
						Main::RemoveEnemy(enemyPool[i]);
						break;
					}
				}
			}

			window.draw(p->Display());
			window.draw(h->Display());
			window.draw(s->Display());

			window.draw(s->sprite1);
			window.draw(s->sprite2);
			window.draw(s->sprite3);

			s->CheckGoal();

		}
		else
		{
			//show lose screen
			sf::Font font;
			sf::Text text;
			sf::Texture texture;
			sf::Sprite sprite;

			std::string s = "assets/arial.ttf";

			if (!font.loadFromFile(s)) {}

			text.setFont(font);
			text.setString("Game Over");
			text.setCharacterSize(64);
			text.setFillColor(sf::Color::Black);
			text.setPosition(240, 300);

			std::string s2 = "assets/sharkdeath.png";

			if (!texture.loadFromFile(s2)) {}

			sprite.setTexture(texture);
			sprite.setPosition(200, 400);

			window.draw(text);
			window.draw(sprite);
		}

		window.display();
	}
}

void Main::AddEnemy(Parachutist* p)
{
	for (int i = 0; i < poolSize; i++)
	{
		if (enemyPool[i] == NULL)
		{
			enemyPool[i] = p;
			return;
		}
	}
}

void Main::RemoveEnemy(Parachutist* p)
{
	for (int i = 0; i < poolSize; i++)
	{
		if (enemyPool[i] == p)
		{
			enemyPool[i] = NULL;
			p->Destroy();
			return;
		}
	}
}
