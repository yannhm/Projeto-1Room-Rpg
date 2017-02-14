#include "Map.h"



Map::Map()
{
	GameMap = new RectangleShape *[28];
	for (int GameMapIterator = 0; GameMapIterator < 28; GameMapIterator++) {
		GameMap[GameMapIterator] = new RectangleShape[28];
	}

	TextureMap.loadFromFile("Resource/Grass.jpg");
	if (!TextureMap.loadFromFile("Resource/Grass.jpg"));
		//error

	TextureWall.loadFromFile("Resource/Wall.png");
	if (!TextureWall.loadFromFile("Resource/Wall.png"));
		//error
}


Map::~Map()
{
}

void Map::IniciarMapa()
{
	for (int GameMapX = 0; GameMapX < 28; GameMapX++) {
		for (int GameMapY = 0; GameMapY < 28; GameMapY++) {
			GameMap[GameMapX][GameMapY].setSize(Vector2f(32 - 1, 32 - 1));
			//GameMap[GameMapX][GameMapY].setFillColor(Color::Green);
			GameMap[GameMapX][GameMapY].setTexture(&TextureMap);
			GameMap[GameMapX][GameMapY].setPosition(sf::Vector2f(32 * GameMapX, 32 * GameMapY));
		}
	}
}

void Map::CriarColunaDeParedes(int YInicio, int YFinal, int XFixo)
{
	for (int GameMapY = YInicio; GameMapY < YFinal; GameMapY++) {
		GameMap[XFixo][GameMapY].setTexture(&TextureWall);
	}
}

void Map::CriarLinhaDeParedes(int XInicio, int XFinal, int YFixo)
{
	for (int GameMapX = XInicio; GameMapX < XFinal; GameMapX++) {
		GameMap[GameMapX][YFixo].setTexture(&TextureWall);
	}
}

void Map::DesenharMapa(RenderWindow &window)
{
	for (int GameMapX = 0; GameMapX < 28; GameMapX++) {
		for (int GameMapY = 0; GameMapY < 28; GameMapY++) {
			window.draw(GameMap[GameMapX][GameMapY]);
		}
	}

	CriarColunaDeParedes(0, 27, 0);
	CriarColunaDeParedes(0, 27, 27);
	CriarLinhaDeParedes(0, 27, 0);
	CriarLinhaDeParedes(0, 28, 27);
}
