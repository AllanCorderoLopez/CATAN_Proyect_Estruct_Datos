#include "Construction.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
float TAMSHAPE = 15;



Construction::Construction() {

    this->radio = 0;

}

Construction::Construction(float coordX, float coordY, int radio) {
    this->radio = radio;
}

CircleShape Construction::renderCity(float coordX, float coordY, float radio, int player) {
    CircleShape triangle(TAMSHAPE,3);
    triangle.setPosition(coordX, coordY);
    triangle.setRadius(TAMSHAPE);
    triangle.setOrigin(TAMSHAPE, TAMSHAPE);
    triangle.setOutlineThickness(2);
    if (player == 0) {
        triangle.setOutlineColor(Color(0, 0, 173, 255));
        triangle.setFillColor(Color(0, 0, 173, 255));
    }
    if (player == 1) {
        triangle.setOutlineColor(Color(209, 42, 8, 255));
        triangle.setFillColor(Color(209, 42, 8, 255));
    }
    if (player == 2) {
        triangle.setOutlineColor(Color(8, 209, 41, 255));
        triangle.setFillColor(Color(8, 209, 41, 255));
    }
    if (player == 3) {
        triangle.setOutlineColor(Color(212, 219, 0, 255));
        triangle.setFillColor(Color(212, 219, 0, 255));
    }
    if (player == 4) {
        triangle.setOutlineColor(Color(0, 0, 173, 255));
        triangle.setFillColor(Color(0, 0, 173, 255));
    }    return triangle;
}

CircleShape Construction::renderSettlement(float coordX, float coordY, float radio, int player) {
    CircleShape circle(TAMSHAPE);
    circle.setPosition(coordX, coordY);
    circle.setRadius(TAMSHAPE);
    circle.setOrigin(TAMSHAPE, TAMSHAPE);
    circle.setOutlineThickness(2);
    if (player == 0) {
        circle.setOutlineColor(Color(0, 0, 173, 255));
        circle.setFillColor(Color(0, 0, 173, 255));
    }
    if (player == 1) {
        circle.setOutlineColor(Color(209, 42, 8, 255));
        circle.setFillColor(Color(209, 42, 8, 255));
    }
    if (player == 2) {
        circle.setOutlineColor(Color(8, 209, 41, 255));
        circle.setFillColor(Color(8, 209, 41, 255));
    }
    if (player == 3) {
        circle.setOutlineColor(Color(212, 219, 0, 255));
        circle.setFillColor(Color(212, 219, 0, 255));
    }
    if (player == 4) {
        circle.setOutlineColor(Color(0, 0, 173, 255));
        circle.setFillColor(Color(0, 0, 173, 255));
    }

    return circle;
}

RectangleShape Construction::renderVecticalRoad(float coordX, float coordY, int player)
{
    RectangleShape  road(Vector2f(10, 60));
    road.setPosition(coordX, coordY);
    road.setOrigin(TAMSHAPE, TAMSHAPE);
    road.setOutlineThickness(2);
    if (player == 0) {
        road.setOutlineColor(Color(0, 0, 173, 255));
        road.setFillColor(Color(0, 0, 173, 255));
    }
    if (player == 1) {
        road.setOutlineColor(Color(209, 42, 8, 255));
        road.setFillColor(Color(209, 42, 8, 255));
    }
    if (player == 2) {
        road.setOutlineColor(Color(8, 209, 41, 255));
        road.setFillColor(Color(8, 209, 41, 255));
    }
    if (player == 3) {
        road.setOutlineColor(Color(212, 219, 0, 255));
        road.setFillColor(Color(212, 219, 0, 255));
    }
    if (player == 4) {
        road.setOutlineColor(Color(0, 0, 173, 255));
        road.setFillColor(Color(0, 0, 173, 255));
    }
    return road;
}
RectangleShape Construction::renderDiagonalRightRoad(float coordX, float coordY, int player)
{
    RectangleShape  road(Vector2f(10, 60));
    road.setPosition(coordX, coordY);
    road.setOrigin(TAMSHAPE, TAMSHAPE);
    road.setOutlineThickness(2);
    road.setRotation(119);
    if (player == 0) {
        road.setOutlineColor(Color(0, 0, 173, 255));
        road.setFillColor(Color(0, 0, 173, 255));
    }
    if (player == 1) {
        road.setOutlineColor(Color(209, 42, 8, 255));
        road.setFillColor(Color(209, 42, 8, 255));
    }
    if (player == 2) {
        road.setOutlineColor(Color(8, 209, 41, 255));
        road.setFillColor(Color(8, 209, 41, 255));
    }
    if (player == 3) {
        road.setOutlineColor(Color(212, 219, 0, 255));
        road.setFillColor(Color(212, 219, 0, 255));
    }
    if (player == 4) {
        road.setOutlineColor(Color(0, 0, 173, 255));
        road.setFillColor(Color(0, 0, 173, 255));
    }
    return road;
}
RectangleShape Construction::renderDiagonalLeftRoad(float coordX, float coordY, int player)
{
    RectangleShape  road(Vector2f(10, 60));
    road.setPosition(coordX, coordY);
    road.setOrigin(TAMSHAPE, TAMSHAPE);
    road.setOutlineThickness(2);
    road.setRotation(55);

    if (player == 0) {
        road.setOutlineColor(Color(0, 0, 173, 255));
        road.setFillColor(Color(0, 0, 173, 255));
    }
    if (player == 1) {
        road.setOutlineColor(Color(209, 42, 8, 255));
        road.setFillColor(Color(209, 42, 8, 255));
    }
    if (player == 2) {
        road.setOutlineColor(Color(8, 209, 41, 255));
        road.setFillColor(Color(8, 209, 41, 255));
    }
    if (player == 3) {
        road.setOutlineColor(Color(212, 219, 0, 255));
        road.setFillColor(Color(212, 219, 0, 255));
    }
    if (player == 4) {
        road.setOutlineColor(Color(0, 0, 173, 255));
        road.setFillColor(Color(0, 0, 173, 255));
    }
    return road;
}
