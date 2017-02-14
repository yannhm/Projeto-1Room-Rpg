#pragma once
#include "Entidade.h"
class Inimigo :
	public Entidade
{
private:
	float velocidadeMovimento, aceleracao;
	int poder;
public:
	Inimigo();
	~Inimigo();

	void atacar();
	void atualizar();
	//void animar(float Velocity, int lado, int MaxNumberOfSpritesPerLine, int Width, int Height);
};

