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

	for (list<Inimigo>::iterator it = inimigo.begin(); it != inimigo.end(); ++it)
	{
		it->atualizar();
	}
	
	for (jogador->beguinIteradorParticula(); !jogador->testaFimParticulaIterador(); jogador->proximoIteradorParticula()) {
		if (jogador->getIteradorParticula()->getTempo() <= 0) {
			jogador->destruirParticulaIterador();
			if (jogador->getSizeListaParticula() == 0) {
				break;
			}
		}
	}
	for (jogador->beguinIteradorParticula(); !jogador->testaFimParticulaIterador(); jogador->proximoIteradorParticula()) {
		jogador->getIteradorParticula()->atualizar();
	}
	

	
}

void Jogo::desenharJogando()
{
	//for (int _y = 0; _y <= window.getSize().y; _y++){

		//if (jogador->getY() == _y){
			jogador->desenhar(window);
		//}

		for (list<Inimigo>::iterator it = inimigo.begin(); it != inimigo.end(); ++it)
		{
			//if (it->getY() == _y){
				it->desenhar(window);
			//}
		}
		if (jogador->getSizeListaParticula() > 0)
		{
			jogador->beguinIteradorParticula();
			if (jogador->getListaParticula().size() >= 1)
			{
				for (jogador->beguinIteradorParticula(); !jogador->testaFimParticulaIterador(); jogador->proximoIteradorParticula())
				{
					//if (jogador->getIteradorParticula()->getY() == _y){
						jogador->getIteradorParticula()->desenhar(window);
					//}
				}
			}
		}
	//}
}
/*
void Jogo::desenharJogando()
{
	//for (int _y = 0; _y <= window.getSize().y; _y++) {

		//if (jogador->getY() == _y) {
			jogador->desenhar(window);
		//}
		
		for (list<Inimigo>::iterator it = inimigo.begin(); it != inimigo.end(); ++it)
		{
		//	if (it->getY() == _y) {
				it->atualizar();
				it->desenhar(window);
		//	}
		}
		//if (jogador->getSizeListaParticula() > 0) {
		//jogador->beguinIteradorParticula();
		if (jogador->getListaParticula().size() >= 1) {
			for (jogador->beguinIteradorParticula(); !jogador->testaFimParticulaIterador(); jogador->proximoIteradorParticula()) {
		//		if (jogador->getIteradorParticula()->getY() == _y) {
					jogador->getIteradorParticula()->desenhar(window);
		//		}
			}
		}

		//}
		//for (list<Particula>::iterator it = particula->begin(); it != particula->end(); ++it)
		//{
		//	it->desenhar(window);
		//}
	//}
}*/
