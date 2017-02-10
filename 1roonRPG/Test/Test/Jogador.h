#pragma once
#include "Entidade.h"

enum Lado
{
	N,	//cima
	NE,	//cima-direita
	E,	//direita
	SE,	//baixo-direita
	S,	//baixo
	SO,	//baixo-esquerda
	O,	//esquerda
	NO,	//cima-esquerda
	NUM_LADOS
};
const int NUM_ANIM = 4;

class Jogador :
	public Entidade
{
private:
	float velocidadeMovimento, aceleracao, criticoProbabilidade;
	int MP, MPmax, espirito, poder, criticoPoder;


public:
	Jogador();
	~Jogador();

	void mover();
	void animar(float Velocity, int lado, int MaxNumberOfSpritesPerLine, int Width, int Height);

	void atacar(int tipoAtaque);
};

