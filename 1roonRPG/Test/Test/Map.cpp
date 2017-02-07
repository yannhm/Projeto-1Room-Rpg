#include "Map.h"



Map::Map()
{
	GameMap = new RectangleShape *[28];
	for (int GameMapIterator = 0; GameMapIterator < 28; GameMapIterator++) {
		GameMap[GameMapIterator] = new RectangleShape[28];
	}
}


Map::~Map()
{
}

void Map::IniciarMapa()
{
	for (int GameMapX = 0; GameMapX < 28; GameMapX++) {
		for (int GameMapY = 0; GameMapY < 28; GameMapY++) {
			GameMap[GameMapX][GameMapY].setSize(Vector2f(32 - 1, 32 - 1));
			GameMap[GameMapX][GameMapY].setFillColor(Color::Green);
			GameMap[GameMapX][GameMapY].setPosition(sf::Vector2f(0,0));
		}
	}
}

void Map::DesenharMapa(RenderWindow &window)
{
	for (int GameMapX = 0; GameMapX < 28; GameMapX++) {
		for (int GameMapY = 0; GameMapY < 28; GameMapY++) {
			window.draw(GameMap[GameMapX][GameMapY]);
		}
	}
}
