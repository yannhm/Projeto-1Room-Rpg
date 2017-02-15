#include "Entidade.h"



Entidade::Entidade()
{
}


Entidade::~Entidade()
{
}

void Entidade::setHPmax(int vidaTotal)
{
	HPmax = vidaTotal;
}

void Entidade::receberDano(int dano)
{
	HP -= dano;
	if (HP <= 0) {
		HP = 0;
		morrer();
	}
}

void Entidade::morrer()
{
	// Evocar efeitos de morte
	// Dropar itens
}

int Entidade::getHP()
{
	return HP;
}
