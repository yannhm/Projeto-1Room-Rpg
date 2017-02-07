#include "Jogo.h"



Jogo::Jogo()
{
}


Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	window.create(sf::VideoMode(800, 600), "1roomRPG!");

	jogador = new Jogador;
	
}

void Jogo::executar()
{
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		/////////////////

		jogador->mover();

		jogador->desenhar(window);

		/////////////////
		window.display();
	}	
}

void Jogo::finalizar()
{

}

void Jogo::desenharJogando()
{
	/*jogador->desenhar(window);
	for (list<Inimigo>::iterator it = inimigos.begin(); it != inimigos.end(); ++it)
	{
		it->desenhar(window);
	}
	for (list<Particula>::iterator it = particula.begin(); it != particula.end(); ++it)
	{
		it->desenhar(window);
	}*/
}
