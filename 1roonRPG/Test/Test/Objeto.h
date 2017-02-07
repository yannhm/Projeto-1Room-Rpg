#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Objeto
{
protected:
	int x, y;


	Texture textura;
	Sprite sprite;
	RectangleShape boxColide;
public:
	Objeto();
	~Objeto();

	void desenhar(RenderWindow &janela);
	void animar(float Velocity, int MaxNumberOfSpritesPerLine, int Width, int Height);
	void setPos(int X, int Y);
	void setCor(int R = 0, int G = 0, int B = 0, int A = 255);
	void setCor(Color &Cor);

	int getX();
	int getY();
};

