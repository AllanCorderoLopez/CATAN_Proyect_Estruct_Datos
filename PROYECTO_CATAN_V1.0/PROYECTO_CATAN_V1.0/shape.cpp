#include "shape.h"

Shape::Shape() {
	this->coordX = 0;
	this->coordY = 0;
}

Shape::Shape(float coordX, float coordY) {
	this->coordX = coordX;
	this->coordY = coordY;
}

void Shape::setCoords(float coordX, float coordY) {
	this->coordX = coordX;
	this->coordY = coordY;
}

float Shape::getCoordX() {
	return coordX;
}


float Shape::getCoordY() {
	return coordY;
}