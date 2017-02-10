#include "Jogo.h"

Jogo::Jogo()
{
}

///////
Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	srand(time(0));
	window.create(sf::VideoMode(896, 896), "1roomRPG!");

	jogador = new Jogador;
	GameMap = new Map;
	
	for (int i = 0; i < 5; i++) {
		inimigo.push_back(Inimigo());
	}


	GameMap->IniciarMapa();
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
		
		//GameMap->DesenharMapa(window);
		
		/////////////////

		
		atualizarJogando();

		desenharJogando(); //jogador->desenhar(window);

		/////////////////
		window.display();
	}	
}

void Jogo::finalizar()
{

}

void Jogo::atualizarJogando()
{
	jogador->mover();
}

void Jogo::desenharJogando()
{
	jogador->desenhar(window);
	
	for (list<Inimigo>::iterator it = inimigo.begin(); it != inimigo.end(); ++it)
	{
		it->desenhar(window);
	}
	/*
	for (list<Particula>::iterator it = particula.begin(); it != particula.end(); ++it)
	{
		it->desenhar(window);
	}
	*/
}
