#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Board
{
private:
	RenderWindow* Menu;
	RectangleShape* optionsMenu[4];

public:
	Board();
	RenderWindow getMenuWindow();
	void drawCircles(vector<CircleShape>);
	void renderMenu();
	void createGameBoard();
	void paintGameBoard();



};


