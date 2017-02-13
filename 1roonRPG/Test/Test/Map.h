#include <SFML\Graphics.hpp>
#pragma once

using namespace sf;
class Map
{
public:
	Map();
	~Map();

	void IniciarMapa();

	void DesenharMapa(RenderWindow &Window);

private:
	RectangleShape **GameMap;
	Texture TextureMap;
};

