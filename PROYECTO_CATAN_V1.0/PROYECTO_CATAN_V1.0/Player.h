#pragma once
#include <iostream>
#include "ListPlayerCards.h"


using namespace std;
class Player
{
private:
	string name;
	int idPlayer;
	int age;
	int color;
	ListPlayerCards listCards;

public:
	Player();
	Player(string, int, int, int, ListPlayerCards);

	string getName();
	int getIdPlayer();
	int getAge();
	int getColor();
	ListPlayerCards getListPlayerCards();



};

