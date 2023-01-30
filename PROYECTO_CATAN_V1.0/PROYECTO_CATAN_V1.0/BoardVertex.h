#pragma once
#include <iostream>
class BoardEdge;

using namespace std;
class BoardVertex
{






	BoardVertex* nextVextex;
	BoardEdge* edge;

	friend class BoardGraph;

public:
	int indexVertex;
	bool hasSettlement = false;
	bool hasCity = false;
	int player; //saber si la construccion es de x jugador


	bool isTerrain = false;
	int terrain = 0;
	BoardVertex(int indexVertex, bool _hasSettlement, bool hasCity, int player, bool _isTerrain, int _terrain);




};

