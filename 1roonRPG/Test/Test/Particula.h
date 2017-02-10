#pragma once
#include "Objeto.h"
class Particula :
	public Objeto
{
private:
	//bool inimiga; // true se for de um inimigo, false se for pro player;	//bola a� algo
	int dano, tempo;//quando o tempo acabar � destruido;
	float velocidade, angulo;
public:
	Particula();
	~Particula();

	Particula(float _x, float _y, int Dano, float Angulo, float Velocidade = 0, int Tempo = 60);

	void atualizar();
	void causarDano();
	void destruir(); //se destroi

	int getDano();
};

