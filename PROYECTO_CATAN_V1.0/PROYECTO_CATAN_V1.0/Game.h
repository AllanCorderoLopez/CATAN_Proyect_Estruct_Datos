#pragma once
#include <iostream>
#include "Board.h"
#include <SFML/Graphics.hpp>
#include "ListPlayerCards.h"


using namespace sf;
using namespace std;
class Game
{
private:
	RenderWindow* firstMenu;
	RenderWindow* secondMenu;
	RenderWindow* loadGameWindow;
	//RenderWindow* logWindow;

	ListCurrentPlayers listCurrentPlayers;


	RectangleShape* optionsfirstMenu[2];
	RectangleShape* optionsSecondMenu[3];
	RectangleShape* registrationFields[2];


	Font* fontTitle;
	Font* fontOptions;
	Text* titleGame;
	Text* labelNewGame;
	Text* labelLoadGame;

	Text* labelSelectPlayers;
	Text* labelTwoPlayers;
	Text* labelThreePlayers;
	Text* labelFourPlayers;

	Vector2i positionMouse;

public:


	Game();
	void startGame();
	void gameType();
	void numberOfPlayers();
	void Register(int);
	void loadGame();
	ListCurrentPlayers getList();
};

