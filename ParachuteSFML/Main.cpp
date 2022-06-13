#include "Main.h"

const static int poolSize = 8;
static Parachutist* enemyPool[8];

int main()
{
	Player* p = new Player();
	Helicopter* h = new Helicopter();

	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Works!");

	window.setFramerateLimit(120);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) { window.close(); }
		}

		window.clear(sf::Color::White);
		h->Timer();

		if (h->dropping)
		{
			Main::AddEnemy(new Parachutist(h->x));
			h->dropping = false;
		}

		p->Move();
		h->Move();

		for (int i = 0; i < poolSize; i++)
		{
			if (enemyPool[i] != NULL)
			{
				enemyPool[i]->Move();
				window.draw(enemyPool[i]->Display());
			}
		}

		window.draw(p->Display());
		window.draw(h->Display());

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
	//paniek (teveel enemies)
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
	//paniek (enemy lost)
}
