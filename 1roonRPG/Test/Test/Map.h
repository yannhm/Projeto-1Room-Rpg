#include <SFML\Graphics.hpp>
#pragma once

using namespace sf;
class Map
{
public:
	Map();
	~Map();

	void IniciarMapa();

	void CriarColunaDeParedes(int YInicio, int YFinal, int XFixo);
	void CriarLinhaDeParedes(int XInicio, int XFinal, int YFixo);
	void DesenharMapa(RenderWindow &Window);

private:
	RectangleShape **GameMap;
	Texture TextureMap;
	Texture TextureWall;
};

