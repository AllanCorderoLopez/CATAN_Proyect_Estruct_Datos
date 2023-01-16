#include<stdio.h>
#include "shape.h"

class Circle {
private:
	int radio;
public:
	Circle();
	Circle(float, float, int);
	void DrawCircle();
	void createCircle(float coordX, float coordY, float radio);

};
