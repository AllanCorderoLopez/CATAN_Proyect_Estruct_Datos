#include "circle.h"
#include <SFML/Graphics.hpp>

using namespace sf;


Circle::Circle() {

    this->radio = 0;

}

Circle::Circle(float coordX, float coordY, int radio) {
    this->radio = radio;
}

void Circle::DrawCircle() {



}

void Circle::createCircle(float coordX, float coordY, float RADIUS) {
    CircleShape circle(RADIUS);
    circle.setFillColor(Color(255, 0, 0, 0));
    circle.setPosition(coordX, coordY);
    circle.setRadius(RADIUS);
    circle.setOrigin(RADIUS, RADIUS);
    circle.setOutlineThickness(2);
    circle.setOutlineColor(Color(255, 0, 0));


}