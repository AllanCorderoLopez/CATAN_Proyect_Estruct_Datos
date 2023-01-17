#include "Board.h"
#include "circle.h"
 
Board::Board()
{
	Menu = new RenderWindow(VideoMode(300,350), "Menu de Opciones");
	/*RenderWindow window({1280, 720}, "Window");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();
		}



		window.display();
	}*/

	for (int i = 0; i < 4; i++) {
		optionsMenu[i] = new RectangleShape({60,15});
		optionsMenu[i]->setFillColor(Color::Green);
	}
	
	optionsMenu[0]->setPosition({70,170});
	optionsMenu[1]->setPosition({150,170});
	optionsMenu[2]->setPosition({70,210});
	optionsMenu[3]->setPosition({150,210});
	renderMenu();
}

void Board::renderMenu()
{
	Menu->clear();
	for (int i = 0; i < 4; i++) {
		Menu->draw(*optionsMenu[i]);
	}
	Menu->display();
	while (Menu->isOpen()) {
		sf::Event event;
		while (Menu->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				Menu->close();
		}
	}
	
}

void Board::createGameBoard()
{
	
}

void Board::paintGameBoard()
{
}
