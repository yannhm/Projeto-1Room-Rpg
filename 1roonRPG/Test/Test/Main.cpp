#include <SFML/Graphics.hpp>
#include <iostream>
#include "Jogo.h"

int main()
{
	
	/*sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);*/

	//sf::CircleShape circle(300.f);

	//circle.setFillColor(sf::Color::White);
	Jogo jogo;

	jogo.inicializar();
	jogo.executar();
	jogo.finalizar();
	//system("pause");

	return 0;
}