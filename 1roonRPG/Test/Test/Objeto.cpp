#include "Objeto.h"



Objeto::Objeto()
{
}


Objeto::~Objeto()
{
}

void Objeto::desenhar(RenderWindow &janela)
{
	janela.draw(this->sprite);
}

void Objeto::animar(float Velocity, int MaxNumberOfSpritesPerLine, int Width, int Height)
{
		static int SpriteConter = 0;

		//Clock SpriterClock;
		//float SpriterTimer = SpriterClock.getElapsedTime().asSeconds();
		//static Time SpriterTime = SpriterClock.getElapsedTime();

		//debug
		//std::cout << SpriterTime.asSeconds() << std::endl;

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			sprite.move(0, -Velocity);
			//sleep(SpriterTime);
			//if (SpriterTime >= seconds(0.1)) {
			//SpriterClock.restart();
			sprite.setTextureRect(IntRect(SpriteConter * Width, Height * 3, Width, Height));
			//}
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			//SpriterClock.restart();
			sprite.move(0, Velocity);
			sprite.setTextureRect(IntRect(SpriteConter * Width, Height * 0, Width, Height));
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			//SpriterClock.restart();
			sprite.move(-Velocity, 0);
			sprite.setTextureRect(IntRect(SpriteConter * Width, Height * 1, Width, Height));
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			//SpriterClock.restart();
			sprite.move(Velocity, 0);
			sprite.setTextureRect(IntRect(SpriteConter * Width, Height * 2, Width, Height));
		}

		SpriteConter++;
		if (SpriteConter == MaxNumberOfSpritesPerLine)
			SpriteConter = 0;
}

void Objeto::setPos(int X, int Y)
{
	x = X;
	y = Y;
}

void Objeto::setCor(int R, int G, int B, int A)
{
	this->sprite.setColor(Color(R,G,B,A));
}

void Objeto::setCor(Color & Cor)
{
	this->sprite.setColor(Cor);
}

int Objeto::getX()
{
	return x;
}

int Objeto::getY()
{
	return y;
}
