#pragma once
#include <iostream>
using namespace std;

class Card
{
private:
	int idCard;
	string nameCard;
	string material;
public:
	Card();
	Card(int);

	int getIdCard();
	string getNameCard();
	string getMaterial();


};

