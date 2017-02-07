#pragma once
#include "Entidade.h"
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
};

