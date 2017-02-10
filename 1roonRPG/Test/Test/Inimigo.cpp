#include "Inimigo.h"



Inimigo::Inimigo()
{
	velocidadeMovimento = 1.f;
	aceleracao = 1.f;
	poder = 50;

	textura.loadFromFile("Resource/inimigoTeste.png");
	if (!textura.loadFromFile("Resource/inimigoTeste.png")) {
		cout << "Falha na Textura do Inimigo.\n";
	}
	sprite.setTexture(textura);
	sprite.setTextureRect(IntRect(0, 0, 64, 32));

	sprite.setScale(1.f, 1.f);
	sprite.setPosition(80, 80);

	

}


Inimigo::~Inimigo()
{
}
