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
};

