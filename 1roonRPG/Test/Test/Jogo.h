#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Jogador.h"
#include "Inimigo.h"
#include "Particula.h"
#include "Map.h"

using namespace sf;
using namespace std;


class Jogo
{
private:
	RenderWindow window;

	Jogador *jogador;
	Map *GameMap;

	list<Particula> particula;
	list<Inimigo> inimigo;

public:
	Jogo();
	~Jogo();

	void inicializar();
	void executar();
	void finalizar();

	void atualizarJogando();
	void desenharJogando();

};

