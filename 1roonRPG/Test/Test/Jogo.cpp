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

	/// Inimigos ///
	for (list<Inimigo>::iterator it = inimigo.begin(); it != inimigo.end(); ++it){
		it->atualizar();
		if (it->getHP() <= 0) {
			list<Inimigo>::iterator aux = it;
			aux++;
			inimigo.erase(it);
			it = aux;
		}
	}
	/*for (jogador->beguinIteradorParticula(); !jogador->testaFimParticulaIterador(); jogador->proximoIteradorParticula()) {
		if (jogador->getIteradorParticula()->getTempo() <= 0) {
			jogador->destruirParticulaIterador();
			if (jogador->getSizeListaParticula() == 0) {
				break;
			}
		}
	}*/
	/// Particulas do Jogador ///
	for (jogador->beguinIteradorParticula(); !jogador->testaFimParticulaIterador(); jogador->proximoIteradorParticula()) {
		jogador->getIteradorParticula()->atualizar();

		/// colisão com os inimigos ///
		for (list<Inimigo>::iterator inimigoIterador = inimigo.begin(); inimigoIterador != inimigo.end(); ++inimigoIterador) {
			if (jogador->getIteradorParticula()->getSprite().getGlobalBounds().intersects(inimigoIterador->getSprite().getGlobalBounds())) {
				list<Particula>::iterator parAux = jogador->getIteradorParticula();
				parAux++;
				
				
				inimigoIterador->receberDano(jogador->getIteradorParticula()->getDano());
				if (inimigoIterador->getHP() <= 0) {
					list<Inimigo>::iterator iniAux = inimigoIterador;
					iniAux++;
					inimigo.erase(inimigoIterador);
					inimigoIterador = iniAux;
					if (inimigo.size() == 0) {
						break;
					}
				}

				if (jogador->getSizeListaParticula() == 0) {
					break;
				}
				jogador->destruirParticulaIterador();
				jogador->getIteradorParticula() = parAux;			
			}
		}
		if (jogador->getSizeListaParticula() == 0) {
			break;
		}
		if (jogador->getIteradorParticula()->getTempo() <= 0) {
			list<Particula>::iterator parAux = jogador->getIteradorParticula();
			parAux++;
			jogador->destruirParticulaIterador();

			if (jogador->getSizeListaParticula() == 0) {
				break;
			}
			jogador->getIteradorParticula() = parAux;
		}
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
