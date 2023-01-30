#pragma once
#include "BoardEdge.h"
#include "BoardVertex.h"
#include"Board.h"

class BoardGraph
{
	BoardVertex* first;
	int size;

public:
	BoardGraph();
	bool graphIsEmpty(); //return true if the graph is empty 
	int getSize(); //get the graph size, count vertices into graph
	BoardVertex* getVertex(int indexVertex); //get graph vertex
	BoardEdge* getEdge(int initial, int terminal); //get graph vertex
	//graph
	void addVertex(int indexVertex, bool hasSettlement, bool hasCity, int player, bool isTerrain, int terrain); //add vertex in the graph 
	void addEdge(int initial, int terminal, bool cloggedRoad, int player);//add edge in the graph
	void getAdjacencyList();
	void deleteVertex(int indexVertex);
	void deleteEdge(int initial, int terminal);
	void deleteEdges(BoardVertex* vertex);
	void deleteEdgeDest(int terminal);//delete edges that have a specific vertex as their destination
	void deleteAll();//delete edges and vertices



	//come





	//saber si tiene asentamientos o cuidades o carreteras
	bool hasSettlement(int indexVertex);
	bool hasCity(int indexVertex);
	bool hasRoad(BoardEdge* edge);
	bool hasTerrain(int indexVertex);

	void hasneighbors();


	//costrucciones
	void buildSettlementOnVertex(int, int);
	void buildCityOnVertex(int,int);
	void buildRoadOnEdge(int,int,int);

	void buildTerrainOnVertex(int indexVertex, int terrain);


	int getTerrainVertex(int indexVertex);


	//carreteras
	void getRoadOnEdge();
	bool roadConnect(int initial, int terminal, int player);
	bool roadConnectToSettlement(int initial, int terminal, int player);
	BoardEdge* getRoad(int initial, int terminal); //get graph road

	bool settlementConnectToRoad(BoardVertex* vertex, int player);
	bool roadMinimumDistance(BoardVertex* vertex);

	//board
	void generateBoard();
	void generateVertices();
	void generateRoadsEdges();


};

