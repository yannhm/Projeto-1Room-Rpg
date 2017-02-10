#include "Jogador.h"
enum Lado
{
	N,	//cima
	NE,
	E,	//direita
	SE,
	S,	//baixo
	SO,
	O,	//esquerda
	NO,
	NUM_LADOS
};


Jogador::Jogador()
{
	velocidadeMovimento = 5;
	aceleracao = 1.f;
	criticoProbabilidade = 0.10f;

	MPmax = 100;
	MP = MPmax;
	espirito = 10;
	poder = 100;
	criticoPoder = 50;


	textura.loadFromFile("Resource/sprite0.png");
	if (!textura.loadFromFile("Resource/sprite0.png")) {
		cout << "Falha na Textura do Personagem.\n";
	}

	sprite.setScale(1.f, 1.f);
	sprite.setPosition(400, 400);

	sprite.setTexture(textura);
	sprite.setTextureRect(IntRect(0, 0, 64, 64));



}


Jogador::~Jogador()
{
}

void Jogador::mover()
{
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		
		if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D)) {
			
			sprite.move(0.f, -velocidadeMovimento * 0.707f);
		}
		else if (!Keyboard::isKeyPressed(Keyboard::S)) {
			sprite.move(0.f, -velocidadeMovimento);
		}
		animar(velocidadeMovimento, NUM_LADOS, sprite.getTextureRect().width, sprite.getTextureRect().height);
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D)) {
			sprite.move(0.f, velocidadeMovimento * 0.707f);
		}
		else{
			sprite.move(0.f, velocidadeMovimento);
		}
		animar(velocidadeMovimento, NUM_LADOS, sprite.getTextureRect().width, sprite.getTextureRect().height);
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::S)) {
			sprite.move(-velocidadeMovimento * 0.707f, 0.f);
		}
		else {
			sprite.move(-velocidadeMovimento, 0.f);
		}
		animar(velocidadeMovimento, NUM_LADOS, sprite.getTextureRect().width, sprite.getTextureRect().height);
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::S)) {
			sprite.move(velocidadeMovimento * 0.707f, 0.f);
		}
		else {
			sprite.move(velocidadeMovimento, 0.f);
		}
		animar(velocidadeMovimento, NUM_LADOS, sprite.getTextureRect().width, sprite.getTextureRect().height);
	}
}

void Jogador::animar(float Velocity, int MaxNumberOfSpritesPerLine, int Width, int Height)
{
	static int SpriteConter = 0;


	if (Keyboard::isKeyPressed(Keyboard::W)) {
		sprite.setTextureRect(IntRect(SpriteConter * Width, Height * 3, Width, Height));
		
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		sprite.setTextureRect(IntRect(SpriteConter * Width, Height * 0, Width, Height));
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		sprite.setTextureRect(IntRect(SpriteConter * Width, Height * 1, Width, Height));
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		sprite.setTextureRect(IntRect(SpriteConter * Width, Height * 2, Width, Height));
	}

	SpriteConter++;
	if (SpriteConter == MaxNumberOfSpritesPerLine) {
		SpriteConter = 0;
	}
}
