#pragma once
#include "NodeTerrain.h"
#include "Terrain.h"

using namespace std;

class ListTerrain
{
private:
    NodeTerrain* first;
    NodeTerrain* current;

public:
    ListTerrain();
    ~ListTerrain();
    void addTerrain(Terrain* );
    string showTerrain(int);
    void showTerrains();
    Terrain* getTerrain(int);

    void addTerrains();

};

