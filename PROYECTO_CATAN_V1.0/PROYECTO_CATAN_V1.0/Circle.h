#include<stdio.h>
#include "shape.h"
#include <SFML/Graphics.hpp>
#include<vector>

using namespace sf;
using namespace std;

class Circle {
private:
	int radio;
	;
public:
	Circle();
	Circle(float, float, int);
	void DrawCircle();
	void createCircle(float coordX, float coordY, float radio);
	void makeCirclesBackground(float coordX, float coordY);
	vector<CircleShape> drawCirclesBackground();
};