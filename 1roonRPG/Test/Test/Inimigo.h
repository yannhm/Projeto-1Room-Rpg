#pragma once
#include "Entidade.h"

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
public:
	Inimigo();
	~Inimigo();
	Inimigo(int tipo);

	void atacar();
	void atualizar();
	//void animar(float Velocity, int lado, int MaxNumberOfSpritesPerLine, int Width, int Height);
};

