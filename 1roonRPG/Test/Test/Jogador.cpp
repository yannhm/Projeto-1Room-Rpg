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

	lado = S;
	angulo = (225 / 180) * 3.14159f;


	textura.loadFromFile("Resource/sprite0.png");
	if (!textura.loadFromFile("Resource/sprite0.png")) {
		cout << "Falha na Textura do Personagem.\n";
	}

	sprite.setScale(1.f, 1.f);
	sprite.setPosition(400, 400);

	sprite.setTexture(textura);
	sprite.setTextureRect(IntRect(0, 0, 64, 64));

	//particula.push_back(Particula(sprite.getPosition().x, sprite.getPosition().y, poder, lado, 3.f, 200));
	iteradorParticula = particula.begin();

}


Jogador::~Jogador()
{
}

void Jogador::atualizar()
{
	mover();

	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		atacar(BOLA_DE_FOGO);
	};

	


}

void Jogador::atacar(int IDhabilidade)
{
	switch (IDhabilidade)
	{
	case BOLA_DE_FOGO:
		particula.push_back(Particula(sprite.getPosition().x, sprite.getPosition().y, poder, angulo, 1.f, 100));
		break;
	case BOLA_DE_GELO:

		break;
	case CHAMAS:

		break;
	case CONE_DE_GELO:

		break;
	default:
		break;
	}
}

void Jogador::mover()
{
	if		(Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S)) 
	{
		if (Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A)) 
		{

			sprite.move(velocidadeMovimento * 0.707f, -velocidadeMovimento * 0.707f);
			angulo = 45;
			animar(velocidadeMovimento, NE, NUM_ANIM, sprite.getTextureRect().width, sprite.getTextureRect().height);
		}
		else if (Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D)) 
		{
			sprite.move(-velocidadeMovimento * 0.707f, -velocidadeMovimento * 0.707f);
			angulo = 135;
			animar(velocidadeMovimento, NO, NUM_ANIM, sprite.getTextureRect().width, sprite.getTextureRect().height);
		}
		else 
		{
			sprite.move(0.f, -velocidadeMovimento);
			angulo = 90;
			animar(velocidadeMovimento, N, NUM_ANIM, sprite.getTextureRect().width, sprite.getTextureRect().height);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::S) && !Keyboard::isKeyPressed(Keyboard::W)) 
	{
		if (Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A)) 
		{

			sprite.move(velocidadeMovimento * 0.707f, velocidadeMovimento * 0.707f);
			angulo = 315;
			animar(velocidadeMovimento, SE, NUM_ANIM, sprite.getTextureRect().width, sprite.getTextureRect().height);
		}
		else if (Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D)) 
		{
			sprite.move(-velocidadeMovimento * 0.707f, velocidadeMovimento * 0.707f);
			angulo = 225;
			animar(velocidadeMovimento, SO, NUM_ANIM, sprite.getTextureRect().width, sprite.getTextureRect().height);
		}
		else
		{
			sprite.move(0.f, velocidadeMovimento);
			angulo = 270;
			animar(velocidadeMovimento, S, NUM_ANIM, sprite.getTextureRect().width, sprite.getTextureRect().height);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D)) 
	{
		sprite.move(-velocidadeMovimento, 0.f);
		angulo = 180;
		animar(velocidadeMovimento, O, NUM_ANIM, sprite.getTextureRect().width, sprite.getTextureRect().height);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A)) 
	{
		sprite.move(velocidadeMovimento, 0.f);
		angulo = 0;
		animar(velocidadeMovimento, E, NUM_ANIM, sprite.getTextureRect().width, sprite.getTextureRect().height);
	}
}

void Jogador::animar(float Velocity, int lado, int MaxNumberOfSpritesPerLine, int Width, int Height)
{
	static int SpriteConter = 0;


	if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::D)) {
		sprite.setTextureRect(IntRect(SpriteConter * Width, Height * lado, Width, Height));
	}

	SpriteConter++;
	if (SpriteConter == MaxNumberOfSpritesPerLine){
		SpriteConter = 0;
	}
}

list<Particula> Jogador::getListaParticula()
{
	return particula;
}

int Jogador::getSizeListaParticula()
{
	return particula.size();
}



list<Particula>::iterator Jogador::getIteradorParticula()
{
	return iteradorParticula;
}

void Jogador::beguinIteradorParticula()
{
	iteradorParticula = particula.begin();
}

void Jogador::proximoIteradorParticula()
{
	iteradorParticula++;
}

void Jogador::destruirParticulaIterador()
{
	particula.erase(iteradorParticula);
	iteradorParticula = particula.begin();
}

bool Jogador::testaFimParticulaIterador()
{
	if (iteradorParticula == particula.end())
		return true;
	else
		return false;
}

bool Jogador::testaInicioParticulaIterador()
{
	if (iteradorParticula == particula.begin())
		return true;
	else
		return false;
}

