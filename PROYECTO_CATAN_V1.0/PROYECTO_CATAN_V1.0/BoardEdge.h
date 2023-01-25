#pragma once
#include <iostream>


class BoardVertex;
class BoardEdge
{
	bool cloggedRoad = false;
	int player;//de que jugador es la carretera
	BoardEdge* next;
	BoardVertex* term;

	friend class BoardGraph;

public: 
	BoardEdge(BoardVertex* _term, bool _cloggedRoad, int player);


};

