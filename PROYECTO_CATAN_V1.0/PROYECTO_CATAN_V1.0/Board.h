#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Board
{
private:
	RenderWindow* Menu;
	RectangleShape* optionsMenu[4];

public:
	Board();
	RenderWindow getMenuWindow();
	void renderMenu();
	void createGameBoard();
	void paintGameBoard();



};

