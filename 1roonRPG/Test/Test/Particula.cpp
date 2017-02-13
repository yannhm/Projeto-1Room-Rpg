#include "Particula.h"



Particula::Particula()
{
}


Particula::~Particula()
{
}

Particula::Particula(float _x, float _y, int Dano, float Angulo, float Velocidade, int Tempo)
{
	dano = Dano;
	tempo = Tempo;
	//velocidade = Velocidade;
	angulo = Angulo;
	vX = Velocidade * cosf(angulo);
	vY = Velocidade * sinf(angulo);

	cout << "vX = " << vX << "\t\tvY = " << vY << endl;

	/////~~////////~~///////////~~////////~~///////////~~////////~~///////////~~////////~~///////////~~////////~~//////
	textura.loadFromFile("Resource/particulaTeste.png");///////////////~~////////~~/////////~~///////~~/////////////~~////////~~//////
	if (!textura.loadFromFile("Resource/particulaTeste.png")) {/////////////~~////////~~////////////////~~////////~~//////////////
		cout << "Falha na Textura da Particula.\n";/////////////////~~////////~~//////////////////////////~~////////~~//////////////////////
	}	//////////~~////////////  TEMOS QUE MUDAR ISTO!!!!!!!! /////////////~~///////////~~//////////~~/////////////~~////////~~//////
	/////~~////////~~//////////~~////////~~////////////~~////////~~///////////~~////////~~///////////~~////////~~///////////~~////////~~//////
	
	sprite.setScale(1.f, 1.f);
	sprite.setPosition(_x, _y);

	sprite.setTexture(textura);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));

}

void Particula::atualizar()
{
	mover();
	tempo--;
	if (tempo < 0) {
		destruir();
	}
}

void Particula::mover()
{
	sprite.move(vX, vY);
}

void Particula::destruir()
{
	//causa dano
	//se destroi
}

int Particula::getTempo()
{
	return tempo;
}
