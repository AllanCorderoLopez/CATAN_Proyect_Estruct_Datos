#include <iostream>
using namespace std;

class Shape {


protected:

	float coordX;
	float coordY;

public:
	Shape();
	Shape(float, float);
	void setCoords(float, float);
	float getCoordX();
	float getCoordY();



};