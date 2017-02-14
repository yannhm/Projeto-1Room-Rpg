#include "Map.h"



Map::Map()
{
	GameMap = new RectangleShape *[28];
	for (int GameMapIterator = 0; GameMapIterator < 28; GameMapIterator++) {
		GameMap[GameMapIterator] = new RectangleShape[28];
	}

	TextureMap.loadFromFile("Resource/Grass.jpg");
	WallTextureMap.loadFromFile("Resource/Dungeon_wall2.jpg");
}


Map::~Map()
{
}

void Map::IniciarMapa()
{
	for (int GameMapX = 0; GameMapX < 28; GameMapX++) {
		for (int GameMapY = 0; GameMapY < 28; GameMapY++) {
			GameMap[GameMapX][GameMapY].setSize(Vector2f(32 - 1, 32 - 1));
			GameMap[GameMapX][GameMapY].setTexture(&TextureMap);
			//GameMap[GameMapX][GameMapY].setFillColor(Color::Green);
			GameMap[GameMapX][GameMapY].setPosition(sf::Vector2f(32 * GameMapX, 32 * GameMapY));
		}
	}
}

void Map::CriarColunaDeParedes(int YInicio, int YFinal, int XFixo)
{
	for (int YPosition = YInicio; YPosition < YFinal; YPosition++) {
		GameMap[XFixo][YPosition].setTexture(&WallTextureMap);
	}
}

void Map::CriarLinhaDeParedes(int XInicio, int XFinal, int YFixo)
{
	for (int XPosition = XInicio; XPosition < XFinal; XPosition++) {
		GameMap[XPosition][YFixo].setTexture(&WallTextureMap);
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
