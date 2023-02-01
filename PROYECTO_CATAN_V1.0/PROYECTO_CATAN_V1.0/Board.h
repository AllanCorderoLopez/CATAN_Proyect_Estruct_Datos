#pragma once
#include <SFML/Graphics.hpp>
#include "listTerrain.h"
#include "Terrain.h"
#include "Node.h"
#include "Game.h"
#include "BoardGraph.h"
#include "BoardVertex.h"
#include <fstream>

using namespace sf;
using namespace std;

class Board
{
private:

	RenderWindow* GameWindow;

	RectangleShape* optionsMenu[4];
	Vector2i positionMouse;

	Font* font;
	Text* titlePlayers;
	Text* playersName;
	Event* passTurn;
	Text* x;
	Text* txtComercio;
	Text* txtSave;

	Text* numberPlayersCardsWool;
	Text* numberPlayersCardsClay;
	Text* numberPlayersCardsWood;
	Text* numberPlayersCardsStone;
	Text* numberPlayersCardsWheat;
	Text* numberPlayersCardsKnight;
	Text* numberPlayersCardsArmy;
	Text* numberPlayersCardsRoute;
	Text* numberPlayersCardsRoad;
	Text* numberPlayersCardsInvention;
	Text* numberPlayersCardsMonopoly;
	Text* numberPlayersCardsTownHall;
	Text* numberPlayersCardsLibrary;
	Text* numberPlayersCardsChurch;
	Text* numberPlayersCardsMarket;
	Text* numberPlayersCardsUniversity;

	Clock* reloj;
	Time* tiempo;



public:

	Board();
	RenderWindow getMenuWindow();
	void drawCircles(vector<CircleShape>);
	void paintTerrains();
	void generateTerrains();
	void renderTerrains();
	void renderMenu(ListCurrentPlayers);
	void createGameBoard();
	void paintGameBoard();
	void selectTerrain();
	void loadImages();
	void paintFixedElements(); //M
	void paintCards();
	vector<int> countCards(Node*);


	int currentPlayer(string);

	void paintSettlemetsOnBoard();
	void paintCityOnBoard();
	void paintRoadsOnBoard();


	void paintVerticalRoads();
	void paintDiagonalRightRoads();
	void paintDiagonalLeftRoads();


	void paintTransparentRectangles();
	int dices();

	void detectHexHorizontalSegment(int);
	void detectHexDiagonalRightSegment(int);
	void detectHexDiagonalLeftSegment(int);
	void detectHexVertice(int);


	void buildTerrainOnVertexBoard();

	void renderGame();
	vector<Terrain*> terrains2;


};


