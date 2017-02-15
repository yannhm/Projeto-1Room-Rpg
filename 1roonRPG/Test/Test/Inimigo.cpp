#include "Inimigo.h"



Inimigo::Inimigo()
{
	static Texture EnemyTexture;
	velocidadeMovimento = 1.f;
	aceleracao = 1.f;
	poder = 50;

	if (!EnemyTexture.loadFromFile("Resource/inimigoTeste.png")) {
		EnemyTexture.loadFromFile("Resource/inimigoTeste.png");
	}
	sprite.setTexture(EnemyTexture);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));

	sprite.setScale(1.f, 1.f);
	sprite.setPosition(rand() % 846 + 25, rand() % 846 + 25);

	

}


Inimigo::~Inimigo()
{
}

void Inimigo::atualizar()
{
	animar(velocidadeMovimento, 2, 32, 32);
}

//void Inimigo::animar(float Velocity, int lado, int MaxNumberOfSpritesPerLine, int Width, int Height)
//{
//	static int SpriteCounter = 0;
//
//	sprite.setTextureRect(IntRect(SpriteCounter * Width, Height * lado, Width, Height));
//
//	SpriteCounter++;
//
//}
