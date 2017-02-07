#include <SFML\Graphics.hpp>
#pragma once

using namespace sf;
class Map
{
public:
	Map();
	~Map();

	void IniciarMapa();

private:
	RectangleShape **GameMap;
	Texture TextureMap;
};

