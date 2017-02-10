#include "Jogador.h"



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
	if (Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S)) {
		if (Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A)) {

			sprite.move(velocidadeMovimento * 0.707f, -velocidadeMovimento * 0.707f);
			animar(velocidadeMovimento, NE, NUM_LADOS, sprite.getTextureRect().width, sprite.getTextureRect().height);
		}
		else if (Keyboard::isKeyPressed(Keyboard::A)) {
			sprite.move(-velocidadeMovimento * 0.707f, -velocidadeMovimento * 0.707f);
			animar(velocidadeMovimento, NO, NUM_LADOS, sprite.getTextureRect().width, sprite.getTextureRect().height);
		}
		else 
		{
			sprite.move(0.f, -velocidadeMovimento);
			animar(velocidadeMovimento, N, NUM_LADOS, sprite.getTextureRect().width, sprite.getTextureRect().height);
		}
		
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		if (Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A)) {

			sprite.move(velocidadeMovimento * 0.707f, velocidadeMovimento * 0.707f);
			animar(velocidadeMovimento, SE, NUM_LADOS, sprite.getTextureRect().width, sprite.getTextureRect().height);
		}
		else if (Keyboard::isKeyPressed(Keyboard::A)) {
			sprite.move(-velocidadeMovimento * 0.707f, velocidadeMovimento * 0.707f);
			animar(velocidadeMovimento, SO, NUM_LADOS, sprite.getTextureRect().width, sprite.getTextureRect().height);
		}
		else{
			sprite.move(0.f, velocidadeMovimento);
			animar(velocidadeMovimento, S, NUM_LADOS, sprite.getTextureRect().width, sprite.getTextureRect().height);
		}
		
	}

	else if (Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D)) {
		
		sprite.move(-velocidadeMovimento, 0.f);
		animar(velocidadeMovimento, O, NUM_LADOS, sprite.getTextureRect().width, sprite.getTextureRect().height);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		sprite.move(velocidadeMovimento, 0.f);
		animar(velocidadeMovimento, E, NUM_LADOS, sprite.getTextureRect().width, sprite.getTextureRect().height);
	}
}

void Jogador::animar(float Velocity, int lado, int MaxNumberOfSpritesPerLine, int Width, int Height)
{
	static int SpriteConter = 0;


	if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D)) {
		sprite.setTextureRect(IntRect(SpriteConter * Width, Height * lado, Width, Height));
	}

	SpriteConter++;
	if (SpriteConter == MaxNumberOfSpritesPerLine) {
		SpriteConter = 0;
	}
}
