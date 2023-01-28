#include "circle.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
float RADIUS = 80;
vector<CircleShape> circles(100);
int cont_Board_Circles = 0;



Circle::Circle() {

    this->radio = 0;

}

Circle::Circle(float coordX, float coordY, int radio) {
    this->radio = radio;
}


CircleShape Circle::createCircle(float coordX, float coordY, float RADIUS) {
    CircleShape circle(RADIUS);
    circle.setFillColor(Color(0, 0, 173, 255));
    circle.setPosition(coordX, coordY);
    circle.setRadius(RADIUS);
    circle.setOrigin(RADIUS, RADIUS);
    circle.setOutlineThickness(2);
    circle.setOutlineColor(Color(0, 0, 173, 255));
    return circle;
}

void Circle::makeCirclesBackground(float coordX, float coordY) {
    CircleShape circle(RADIUS);

    circles[cont_Board_Circles] = circle;
    circles[cont_Board_Circles].setFillColor(Color(255, 0, 0, 0));
    circles[cont_Board_Circles].setPosition(coordX, coordY);
    circles[cont_Board_Circles].setRadius(RADIUS);
    circles[cont_Board_Circles].setOrigin(RADIUS, RADIUS);
    circles[cont_Board_Circles].setOutlineThickness(2);
    circles[cont_Board_Circles].setOutlineColor(Color(255, 0, 0,255));


}

vector<CircleShape> Circle::drawCirclesBackground() {
    cont_Board_Circles = 0;
    float coordX = 500;
    float coordY = 20;



    for (int i = 0; i < 4; i++) {
        makeCirclesBackground((coordX+15) + (i * 120), coordY);
        cont_Board_Circles++;

    }
    for (int i = 0; i < 5; i++) {
        makeCirclesBackground(coordX - 50 + (i * 120), coordY + 100);
        cont_Board_Circles++;

    }

    for (int i = 0; i < 6; i++) {
        makeCirclesBackground(coordX - 110 + (i * 120), coordY + (100 * 2));
        cont_Board_Circles++;
    }
    for (int i = 0; i < 7; i++) {
        makeCirclesBackground(coordX - 170 + (i * 120), coordY + (100 * 3));
        cont_Board_Circles++;
    }
    for (int i = 0; i < 6; i++) {
        makeCirclesBackground(coordX - 110 + (i * 120), coordY + (100 * 4));
        cont_Board_Circles++;
    }

    for (int i = 0; i < 5; i++) {
        makeCirclesBackground(coordX - 50 + (i * 120), coordY + (100 * 5));
        cont_Board_Circles++;

    }

    for (int i = 0; i < 4; i++) {
        makeCirclesBackground(coordX+15 + (i * 120), coordY + (100 * 6));
        cont_Board_Circles++;

    }
    /*
    
    
    



    for (int i = 0; i < 5; i++) {
        makeCirclesBackground(coordX - 50 + (i * 100), coordY + (87 * 5));
        cont_Board_Circles++;

    }

    for (int i = 0; i < 4; i++) {
        makeCirclesBackground(coordX + (i * 100), coordY + (87 * 6));
        cont_Board_Circles++;

    }
    */
    return circles;

}