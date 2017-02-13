#pragma once
#include "Objeto.h"
class Particula :
	public Objeto
{
private:
	//bool inimiga; // true se for de um inimigo, false se for pro player;	//bola a� algo
	int dano, tempo;//quando o tempo acabar � destruido;
	float vX, vY, angulo; // vX e vY s�o a velocidade conforme o angulo
public:
	Particula();
	~Particula();

	Particula(float _x, float _y, int Dano, float Angulo, float Velocidade = 0, int Tempo = 60);

	void atualizar();
	void mover();
	void causarDano();
	void destruir(); //se destroi

	int getDano();
	int getTempo();

};

