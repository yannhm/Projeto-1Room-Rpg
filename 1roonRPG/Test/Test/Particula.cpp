#include "Particula.h"



Particula::Particula()
{
}


Particula::~Particula()
{
}

Particula::Particula(float _x, float _y, int Dano, float Angulo, float Velocidade, int Tempo)
{
	static Texture ParticleTexture;

	ParticleTexture.loadFromFile("Resource/particulaTeste.png");
	dano = Dano;
	tempo = Tempo;
	//velocidade = Velocidade;
	angulo = Angulo;
	vX = Velocidade * cosf((angulo / 180) * 3.14159f);
	vY = Velocidade * -sinf((angulo / 180) * 3.14159f);
	
	/*if (!ParticleTexture.loadFromFile("Resource/particulaTeste.png")) {
		ParticleTexture.loadFromFile("Resource/particulaTeste.png");
	}*/
	sprite.setOrigin(16, 16);

	sprite.setTexture(ParticleTexture);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));

	sprite.setScale(1.0f, 1.0f);
	sprite.setPosition(_x, _y);
	sprite.setRotation(-angulo);
}

void Particula::atualizar()
{
	mover();
	tempo--;
	if (tempo <= 0) {
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
