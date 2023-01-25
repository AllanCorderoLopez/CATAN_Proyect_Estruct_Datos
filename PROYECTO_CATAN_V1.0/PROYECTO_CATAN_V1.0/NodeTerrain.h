#pragma once

#include "Terrain.h"
#include <sstream>
using namespace std;
class NodeTerrain
{
private: 
	Terrain* data;
	NodeTerrain* nextNode;

public:
	NodeTerrain(Terrain*, NodeTerrain*);

	void setDataTerrain(Terrain*);
	Terrain* getDataTerrain();

		
	void setNextNode(NodeTerrain*);
	NodeTerrain* getNextNode();


};

