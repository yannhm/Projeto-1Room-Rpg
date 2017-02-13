#pragma once
#include <list>
#include "Entidade.h"
#include "Particula.h"

enum Skill
{
	BOLA_DE_FOGO,
	BOLA_DE_GELO,
	CHAMAS,
	CONE_DE_GELO,
};

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
	float velocidadeMovimento, aceleracao, criticoProbabilidade, angulo;
	int MP, MPmax, espirito, poder, criticoPoder, lado;

	list<Particula> particula;
	list<Particula>::iterator iteradorParticula;

public:
	Jogador();
	~Jogador();

	void atualizar();

	void atacar(int IDhabilidade);

	void mover();
	void animar(float Velocity, int lado, int MaxNumberOfSpritesPerLine, int Width, int Height);

	list<Particula> getListaParticula();
	void dispararParticula(Particula par);
	int getSizeListaParticula();

	list<Particula>::iterator getIteradorParticula();
	void beguinIteradorParticula();
	void proximoIteradorParticula();
	void anteriorIteradorParticula();

	void destruirParticulaIterador();

	bool testaFimParticulaIterador();
	bool testaInicioParticulaIterador();//
};

