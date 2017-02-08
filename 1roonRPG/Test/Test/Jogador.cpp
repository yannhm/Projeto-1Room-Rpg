#include "Jogador.h"

///////// ei

Jogador::Jogador()
{
	velocidadeMovimento = 2;

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
		sprite.move(0, -velocidadeMovimento);
		animar(velocidadeMovimento, 4, 133 / 4, 210 / 4);
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		sprite.move(0, velocidadeMovimento);
		animar(velocidadeMovimento, 4, 133 / 4, 210 / 4);
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		sprite.move(-velocidadeMovimento, 0);
		animar(velocidadeMovimento, 4, 133 / 4, 210 / 4);
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		sprite.move(velocidadeMovimento, 0);
		animar(velocidadeMovimento, 4, 133 / 4, 210 / 4);
	}
}
