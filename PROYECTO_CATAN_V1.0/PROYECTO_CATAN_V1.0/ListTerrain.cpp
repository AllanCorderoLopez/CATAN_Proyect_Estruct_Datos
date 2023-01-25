#include "ListTerrain.h"
#include <cstddef>
#include "NodeTerrain.h"
#include "Terrain.h"
#include<iostream>
using namespace std;

ListTerrain::ListTerrain() {
	first = current = NULL;
}



void ListTerrain::addTerrain(Terrain* data) {
	current = first;
	if (first == NULL) {
		first = new NodeTerrain(data, NULL);
	}
	else {
		first = new NodeTerrain(data, current);
	}

}



string ListTerrain::showTerrain(int pos) {
	stringstream ss;

	current = first;
	while (current && current->getDataTerrain()->getId() != pos) {
		current = current->getNextNode();

	}
	if (!current || current->getDataTerrain()->getId() != pos) {
		ss << "Terreno no encontrado" << endl;
	}
	else {
		ss << current->getDataTerrain()->getNameTerrain() << endl;
	}
	return ss.str();
}


Terrain* ListTerrain::getTerrain(int pos) {
	stringstream ss;

	current = first;
	while (current && current->getDataTerrain()->getId() != pos) {
		current = current->getNextNode();

	}
	if (!current || current->getDataTerrain()->getId() != pos) {
		ss << "Terreno no encontrado" << endl;
	}
	else {
		ss << current->getDataTerrain()->getNameTerrain() << endl;
	}
	return current->getDataTerrain();
}
void ListTerrain::showTerrains() {


	current = first;
	while (current && current->getDataTerrain() != NULL) {

		cout << "Terreno: " << current;
		current = current->getNextNode();

	}



}

void ListTerrain::addTerrains() {


	addTerrain(new Terrain(0, "FOREST", 1, 1, "RECURSOS/TABLERO/TERRENO-MADERA.png"));
	addTerrain(new Terrain(1, "HILLS", 1, 1, "RECURSOS/TABLERO/TERRENO-ARCILLA.png"));
	addTerrain(new Terrain(2, "MOUNTAIN", 1, 1, "RECURSOS/TABLERO/TERRENO-PIEDRA.png"));
	addTerrain(new Terrain(3, "PASTURE", 1, 1, "RECURSOS/TABLERO/TERRENO-LANA.png"));
	addTerrain(new Terrain(4, "SOWN", 1, 1, "RECURSOS/TABLERO/TERRENO-TRIGO.png"));
	addTerrain(new Terrain(5, "DESERT", 1, 1, "RECURSOS/TABLERO/TERRENO-DESIERTO.png"));


}
