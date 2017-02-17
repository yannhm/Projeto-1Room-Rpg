#include "Inimigo.h"



Inimigo::Inimigo()
{
	static Texture EnemyTexture;

	HPmax = 80;
	HP = HPmax;

	velocidadeMovimento = 1.f;
	aceleracao = 1.f;
	poder = 5;

	if (!EnemyTexture.loadFromFile("Resource/inimigoTeste.png")) {
		EnemyTexture.loadFromFile("Resource/inimigoTeste.png");
	}
	sprite.setTexture(EnemyTexture);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));

	sprite.setScale(1.5f, 1.5f);
	sprite.setPosition(rand() % 800 + 40, rand() % 806 + 45);

	sprite.setOrigin(16, 30);

}


Inimigo::~Inimigo()
{
}

Inimigo::Inimigo(int tipo)
{
	static Texture EnemyTexture;
	//tempoAnim = time(0);
	HPmax = 80;
	

	velocidadeMovimento = 1.f;
	aceleracao = 1.f;
	poder = 5;

	if (!EnemyTexture.loadFromFile("Resource/inimigoTeste.png")) {
		EnemyTexture.loadFromFile("Resource/inimigoTeste.png");
	}
	sprite.setTexture(EnemyTexture);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));

	sprite.setScale(1.5f, 1.5f);
	sprite.setPosition(rand() % 800 + 40, rand() % 806 + 45);

	sprite.setOrigin(16, 30);

	switch (tipo)
	{
	case NORMAL:

		break;
	case BERSEKER:
		setCor(250, 50, 50);
		sprite.setScale(1.5f, 1.5f);
		HPmax += 200; // 30%
		break;

	case BOSS:

		setCor(180, 0, 0);
		HPmax = 5000;
		sprite.setScale(10.f, 10.f);
		break;
	default:
		break;
	}

	HP = HPmax;
	
}

void Inimigo::atualizar()
{
	if (podeAnimar(2.0f)) {
		animar(velocidadeMovimento, 2, 32, 32);
	}

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
