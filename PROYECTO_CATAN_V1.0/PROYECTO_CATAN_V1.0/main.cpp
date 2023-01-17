#include <SFML/Graphics.hpp>
#include "circle.h"
#include "Board.h"
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;
//float RADIUS = 75;
//vector<CircleShape> circles(10);






int main()
{


    //RenderWindow window({ 1280, 720 }, "Window");


    //  void drawBoard();


    //float Pos_Circle_X = 300;
    //float Pos_Circle_Y = 125;
    

    // We're simply abusing a `CircleShape` here,
    // since a circle defined by 6 points IS a hexagon!
    //circle vertice

    /*
    CircleShape circleVertice(5);
    circleVertice.setFillColor(Color(0, 98, 117, 0));
    circleVertice.setPosition(350, 156);
    circleVertice.setRadius(5);
    circleVertice.setOrigin(5, 5);


    RectangleShape line(Vector2f(63, 3.5));
    line.rotate(90);
    line.setPosition(350, 93);
    line.setFillColor(Color(255, 0, 0, 0));


    RectangleShape line2(Vector2f(90, 2));
    line2.rotate(45);
    line2.setPosition(353, 160);
    line2.setFillColor(Color(255, 0, 0, 255));


    RectangleShape line3(Vector2f(90, 2));
    line3.rotate(120);
    line3.setPosition(380, 80);
    line3.setFillColor(Color(255, 0, 0, 255));


    sf::CircleShape hexagon(58, 6);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(2);
    hexagon.setFillColor(Color(255, 0, 0, 0));
    hexagon.setOrigin(Pos_Circle_X, Pos_Circle_Y);
    hexagon.setPosition(Pos_Circle_X + 342, Pos_Circle_Y + 67);


    CircleShape circle(RADIUS);


    circles.push_back(CircleShape());
    circles.back() = circle;


    circles[0] = circle;
    circles[0].setFillColor(Color(255, 0, 0, 0));
    circles[0].setPosition(Pos_Circle_X, Pos_Circle_Y);
    circles[0].setRadius(RADIUS);
    circles[0].setOrigin(RADIUS, RADIUS);
    circles[0].setOutlineThickness(2);
    circles[0].setOutlineColor(Color(255, 0, 0));


    circles[1] = circle;
    circles[1].setFillColor(Color(255, 0, 0, 0));
    circles[1].setPosition(Pos_Circle_X + 100, Pos_Circle_Y);
    circles[1].setRadius(RADIUS);
    circles[1].setOrigin(RADIUS, RADIUS);
    circles[1].setOutlineThickness(2);
    circles[1].setOutlineColor(sf::Color(200, 200, 0));


    circles[2] = circle;
    circles[2].setFillColor(Color(255, 0, 0, 0));
    circles[2].setPosition(Pos_Circle_X + 50, Pos_Circle_Y + 90);
    circles[2].setRadius(RADIUS);
    circles[2].setOrigin(RADIUS, RADIUS);
    circles[2].setOutlineThickness(2);
    circles[2].setOutlineColor(sf::Color(200, 200, 0));

    bool shape1_active = false;
    bool shape2_active = false;
    bool shape3_active = false;




    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {


            switch (event.type) {

            case Event::MouseMoved:
                cout << "X: " << event.mouseMove.x << endl;
                cout << "Y: " << event.mouseMove.y << endl;
            }

            int dx = event.mouseMove.x - circles[0].getPosition().x;
            int dy = event.mouseMove.y - circles[0].getPosition().y;
            if (dx < 0) { dx = -dx; }
            if (dy < 0) { dy = -dy; }

            float d1 = dx * dx;
            float d2 = dy * dy;
            float d3 = d1 + d2;
            float d = sqrt(d3);

            if (d <= RADIUS) {
                circles[0].setOutlineColor(Color(255, 255, 0));
                cout << "----- Mouse dentro del circulo -------" << endl;
                shape1_active = true;
            }


            else {
                circles[0].setOutlineColor(Color(255, 0, 0));
                cout << "----- Mouse fuera del circulo -------" << endl;
                shape1_active = false;
            }


            //-------------------- segundo circulo


            int dxCirc = event.mouseMove.x - circles[1].getPosition().x;
            int dyCirc = event.mouseMove.y - circles[1].getPosition().y;
            if (dxCirc < 0) { dxCirc = -dxCirc; }
            if (dyCirc < 0) { dyCirc = -dyCirc; }

            float d1Circ = dxCirc * dxCirc;
            float d2Circ = dyCirc * dyCirc;
            float d3Circ = d1Circ + d2Circ;
            float dCirc = sqrt(d3Circ);


            if (dCirc <= RADIUS) {
                circles[1].setOutlineColor(Color(255, 255, 0));
                cout << "----- Mouse dentro del circulo -------" << endl;
                shape2_active = true;
            }

            else {
                circles[1].setOutlineColor(Color(255, 0, 0));
                cout << "----- Mouse fuera del circulo -------" << endl;
                shape1_active = false;
            }

            //-------------------- tercer circulo


            int dxCirc3 = event.mouseMove.x - circles[2].getPosition().x;
            int dyCirc3 = event.mouseMove.y - circles[2].getPosition().y;
            if (dxCirc3 < 0) { dxCirc3 = -dxCirc3; }
            if (dyCirc3 < 0) { dyCirc3 = -dyCirc3; }

            float d1Circ3 = dxCirc3 * dxCirc3;
            float d2Circ3 = dyCirc3 * dyCirc3;
            float d3Circ3 = d1Circ3 + d2Circ3;
            float dCirc3 = sqrt(d3Circ3);


            if (dCirc3 <= RADIUS) {
                circles[2].setOutlineColor(Color(255, 255, 0));
                cout << "----- Mouse dentro del circulo -------" << endl;
                shape3_active = true;
            }

            else {
                circles[2].setOutlineColor(Color(255, 0, 0));
                cout << "----- Mouse fuera del circulo -------" << endl;
                shape3_active = false;
            }



            //interseccion de 2 circulos
            if (shape1_active == true && shape2_active == true) {
                cout << "----- Interseccion de circulos -------" << endl;
                line.setFillColor(Color(0, 98, 117, 255));
            }

            else {
                line.setFillColor(Color(255, 0, 0, 0));
            }

            //interseccion de 3 circulos
            if (shape1_active == true && shape2_active == true && shape3_active == true) {
                cout << "----- Interseccion de circulos -------" << endl;
                //line.setFillColor(Color(0, 0, 181));
                circleVertice.setFillColor(Color(0, 98, 117, 255));
                line.setFillColor(Color(255, 0, 0, 0));

            }
            else {
                circleVertice.setFillColor(Color(0, 98, 117, 0));

            }







            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(circles[0]);
        window.draw(circles[1]);
        window.draw(circles[2]);
        window.draw(hexagon);
        window.draw(line);
        // window.draw(line2);
        // window.draw(hexagon);
         //   window.draw(line3);

        window.draw(circleVertice);


        //for (int y = 0; y < 1; ++y) {
        //    for (int x = 0; x < 2; ++x) {
        //        // The horizontal/vertical offsets of 50 and 40
        //        // might feel off, but that's due to the way SFML
        //        // calculates the circle outline
        //       // hexagon.setPosition(100+(x*100), 100);
        //        circle.setPosition(100 + (x * 100), 300);
        //        circle.setFillColor(sf::Color(x * 25, y * 25, 0));
        //       // window.draw(hexagon);
        //        window.draw(circle);
        //    }
        //}

        window.display();
    }


    */

    Board menu;
    menu.renderMenu();

    /*while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

        }

        if (event.type == sf::Event::Closed)
            window.close();
        window.clear(sf::Color::White);
        
        window.display();
    }*/

}


void drawCircle(float radius, float coordX, float coordY) {

}