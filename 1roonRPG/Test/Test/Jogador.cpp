#include "Jogador.h"



Jogador::Jogador()
{
	velocidadeMovimento = 1;

	textura.loadFromFile("Resource/Just_Test.png");
	if (!textura.loadFromFile("Resource/Just_Test.png")) {
		cout << "Falha na Texture Personagem.\n";
	}

	sprite.setScale(0.7f, 0.7f);
	sprite.setPosition(10, 10);

	sprite.setTexture(textura);
	sprite.setTextureRect(IntRect(0, 0, 133 / 4, 210 / 4));
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
		else{
			sprite.move(0.f, -velocidadeMovimento);
		}
		animar(velocidadeMovimento * 0.2, 4, 133 / 4, 210 / 4);
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D)) {
			sprite.move(0.f, velocidadeMovimento * 0.707f);
		}
		else{
			sprite.move(0.f, velocidadeMovimento);
		}
		animar(velocidadeMovimento * 0.2, 4, 133 / 4, 210 / 4);
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::S)) {
			sprite.move(-velocidadeMovimento * 0.707f, 0.f);
		}
		else {
			sprite.move(-velocidadeMovimento, 0.f);
		}
		animar(velocidadeMovimento * 0.2, 4, 133 / 4, 210 / 4);
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::S)) {
			sprite.move(velocidadeMovimento * 0.707f, 0.f);
		}
		else {
			sprite.move(velocidadeMovimento, 0.f);
		}
		animar(velocidadeMovimento * 0.2, 4, 133 / 4, 210 / 4);
	}
}
