#pragma once
#include <SFML/Graphics.hpp>
#include "listTerrain.h"
#include "Terrain.h"
#include "Node.h"
#include "Game.h"
#include "BoardGraph.h"
#include "BoardVertex.h"

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
<<<<<<< Updated upstream
	vector<int> countCardsWool(Node*);
=======
	void paintSettlemetsOnBoard();
>>>>>>> Stashed changes


	void detectHexHorizontalSegment();
	void detectHexDiagonalRightSegment();
	void detectHexDiagonalLeftSegment();
	void detectHexVertice();


	void buildTerrainOnVertexBoard();

	void renderGame();
	vector<Terrain*> terrains2;


};


