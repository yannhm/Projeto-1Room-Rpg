#pragma once
#include "Objeto.h"
class Entidade :
	public Objeto
{
protected:
	int HP, HPmax;
public:
	Entidade();
	~Entidade();

	void setHPmax(int vidaTotal);
	void receberDano(int dano);
	void morrer();

	int getHP();

};

