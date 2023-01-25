#include "Terrain.h"


Terrain::Terrain(int id, string nameString, int coordX, int coordY, string path) {
	this->id = id;
	this->coordX = coordX;
	this->coordY = coordY;
	this->nameTerrain = nameString;
	this->path = path;
}

void Terrain::setPathTerrain(string path) {
	this->path = path;
}

string Terrain::getPathTerrain() {
	return path;
}
void Terrain::setId(int id) {
	this->id = id;
}


void Terrain::setNameTerrain(string nameString) {
	this->nameTerrain = nameString;
}

void Terrain::setCoords(int coordX, int coordY) {
	this->coordX = coordX;
	this->coordY = coordY;
}

int Terrain::getCoordX() {
	return coordX;
}


int Terrain::getCoordY() {
	return coordX;
}

int Terrain::getId() {
	return this->id;
}


string Terrain::getNameTerrain() {
	return this->nameTerrain;
}