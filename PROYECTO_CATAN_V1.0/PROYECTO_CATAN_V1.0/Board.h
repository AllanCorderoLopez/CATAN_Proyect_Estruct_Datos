#pragma once
#include <SFML/Graphics.hpp>
#include "listTerrain.h"
#include "Terrain.h"
using namespace sf;
using namespace std;

class Board
{
private:

	RenderWindow* Game;
	RectangleShape* optionsMenu[4];

public:

	Board();
	RenderWindow getMenuWindow();
	void drawCircles(vector<CircleShape>);
	void paintTerrains();
	void generateTerrains();
	void renderTerrains();
	void renderMenu();
	void createGameBoard();
	void paintGameBoard();
	void selectTerrain();
	void loadImages();

	void detectHexHorizontalSegment();
	void detectHexDiagonalRightSegment();
	void detectHexDiagonalLeftSegment();
	void detectHexVertice();

};


