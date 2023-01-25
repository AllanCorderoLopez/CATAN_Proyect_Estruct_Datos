#pragma once
#include <sstream>
using namespace std;
class Terrain
{

private: 


	int id;
	string path;
	string nameTerrain;
	int coordX, coordY;


public:

	Terrain(int,string,int,int, string);
	
	void setId(int);
	void setNameTerrain(string);

	int getId();
	string getNameTerrain();
	void setPathTerrain(string);
	string getPathTerrain();

	void setCoords(int, int);
	int getCoordX();
	int getCoordY();
};

