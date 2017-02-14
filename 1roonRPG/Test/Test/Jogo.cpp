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
	GameMap->CriarColunaDeParedes(0, 27, 0);
	GameMap->CriarColunaDeParedes(0, 27, 27);
	GameMap->CriarLinhaDeParedes(0, 27, 0);
	GameMap->CriarLinhaDeParedes(0, 28, 27);
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
		
		GameMap->DesenharMapa(window);
		
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
	jogador->atualizar();
	if (jogador->getListaParticula().size() > 1) {
		
		for (jogador->beguinIteradorParticula(); !jogador->testaFimParticulaIterador(); jogador->proximoIteradorParticula()) {
			if (jogador->getIteradorParticula()->getTempo() <= 0) {
				jogador->destruirParticulaIterador();
			}
		}
		for (jogador->beguinIteradorParticula(); !jogador->testaFimParticulaIterador(); jogador->proximoIteradorParticula()) {
			jogador->getIteradorParticula()->atualizar();
		}
	}

	
}

void Jogo::desenharJogando()
{
	jogador->desenhar(window);
	
	for (list<Inimigo>::iterator it = inimigo.begin(); it != inimigo.end(); ++it)
	{
		it->atualizar();
		it->desenhar(window);
	}
	//if (jogador->getSizeListaParticula() > 0) {
	//jogador->beguinIteradorParticula();
	if (jogador->getListaParticula().size() > 1) {
		for (jogador->beguinIteradorParticula(); !jogador->testaFimParticulaIterador(); jogador->proximoIteradorParticula()) {
			jogador->getIteradorParticula()->desenhar(window);
		}
	}
	
	//}
	/*for (list<Particula>::iterator it = particula->begin(); it != particula->end(); ++it)
	{
		it->desenhar(window);
	}*/
	
}
