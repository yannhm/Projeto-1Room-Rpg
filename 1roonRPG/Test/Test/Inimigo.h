#pragma once
#include <list>
#include "Entidade.h"
#include "Particula.h"

enum TipoInimigo
{
	NORMAL,
	BERSEKER,
	BOSS
};

class Inimigo :
	public Entidade
{
private:
	float velocidadeMovimento, aceleracao;
	int tipo, poder;

	list<Particula> particula;
	list<Particula>::iterator IteradorParticula;

public:
	Inimigo();
	~Inimigo();
	Inimigo(int tipo);

	void atacar(int AnguloDoJogador);
	void atualizar();
	void DesenharParticulas(RenderWindow &window);
	//void animar(float Velocity, int lado, int MaxNumberOfSpritesPerLine, int Width, int Height);
};

