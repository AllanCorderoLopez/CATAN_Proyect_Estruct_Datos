#pragma once
#include<stdio.h>
#include <SFML/Graphics.hpp>
#include<vector>
using namespace sf;
using namespace std;

class Construction
{
private:
	int radio;
	
public:
	Construction();
	Construction(float, float, int);


	CircleShape renderCity(float coordX, float coordY, float radio, int player);
	CircleShape renderSettlement(float coordX, float coordY, float radio, int player);

	RectangleShape renderVecticalRoad(float coordX, float coordY, int player);
	RectangleShape renderDiagonalRightRoad(float coordX, float coordY, int player);
	RectangleShape renderDiagonalLeftRoad(float coordX, float coordY, int player);

};


