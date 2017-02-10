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
	velocidade = Velocidade;
	angulo = Angulo;

	textura.loadFromFile("Resource/particulaTeste.png");
	if (!textura.loadFromFile("Resource/particulaTeste.png")) {
		cout << "Falha na Textura da Particula.\n";
	}

	sprite.setScale(1.f, 1.f);
	sprite.setPosition(_x, _y);

	sprite.setTexture(textura);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));

}

void Particula::atualizar()
{
	//mover
	tempo--;
	if (tempo < 0) {
		destruir();
	}
}

void Particula::destruir()
{
	//causa dano
	//se destroi
}
