#include "Main.h"

const static int poolSize = 4;
static Parachutist* enemyPool[4];
static int totalCount = 0;

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

		h->Timer();
		if (h->dropping)
		{
			totalCount++;
			std::cout << "total: ";
			std::cout << totalCount;
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
