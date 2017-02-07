#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Jogador.h"
#include "Inimigo.h"
#include "Particula.h"


using namespace sf;
using namespace std;


class Jogo
{
private:
	RenderWindow window;

	Jogador *jogador;
	list<Particula> particula;
	list<Inimigo> inimigos;

public:
	Jogo();
	~Jogo();

	void inicializar();
	void executar();
	void finalizar();

	void desenharJogando();

};

