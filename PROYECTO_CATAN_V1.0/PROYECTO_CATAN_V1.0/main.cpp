#include <SFML/Graphics.hpp>
#include "circle.h"
#include "Board.h"
#include "BoardGraph.h"
#include "listTerrain.h"
#include "Terrain.h"
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;
//float RADIUS = 75;
//vector<CircleShape> circles(10);






int main()
{






    Game juego;
    juego.startGame();




    /*
    * 
    * 
    * 
    * 







    BoardGraph* graph = new BoardGraph();
    int op = -1;



    sf::Texture texture;
    if (!texture.loadFromFile("image.png"))
    {
        // error...
    }








    while (op!=0) {
        system("cls");
        cout << "1) Insertar vertices" << endl;
        cout << "2) Insertar aristas" << endl;
        cout << "3) Obtener tamano" << endl;
        cout << "4) Mostrar lista de adyacencia" << endl;
        cout << "5) Eliminar vertice" << endl;
        cout << "6) Eliminar arista" << endl;
        cout << "7) Eliminar todo" << endl;
        cout << "8) Agregar Asentamiento" << endl;
        cout << "9) Ver Asentamiento de un vertice" << endl;
        cout << "10) Agregar ciudad" << endl;
        cout << "11) Ver ciudad de un vertice" << endl;
        cout << "12) Agregar carretera" << endl;
        cout << "13) Ver carretera " << endl;



        cout << "0) Salir" << endl;
        cout<<"\n";
        cout << "Ingrese una opcion: " << endl;
        cin >> op;
        system("cls");

        switch (op)
        {
        case 1:
            graph->generateVertices();
            system("pause");

            break;
        case 2:
            graph->generateRoadsEdges();



            system("pause");

            break;
        case 3:
            cout<<"El tamano es: "<<graph->getSize()<<endl;
            system("pause");

            break;
        case 4:
            if (graph->graphIsEmpty()) {
                cout << "Grafo vacio" << endl;
                system("pause");

                break;
            }
            graph->getAdjacencyList();
            system("pause");

            break;
        case 5:
            int vert;
            cout << "Ingrese el vertice a eliminar: ";
            cin >> vert;
            graph->deleteVertex(vert);
            system("pause");
            break;
        case 6:
            int vertIni, vertTerm;
            cout << "Ingrese el vertice inicial : ";
            cin >> vertIni;
            cout << "Ingrese el vertice final : ";
            cin >> vertTerm;

            graph->deleteEdge(vertIni,vertTerm);
            system("pause");

            break;
        case 7:
            graph->deleteAll();
            system("pause");

            break;
        case 8:

            graph->buildSettlementOnVertex();
            system("pause");

            break;
        case 9:
            int hasvertexSettlement;
            cout << "Ingrese un vertice para saber si tiene un asentamiento: ";
            cin >> hasvertexSettlement;
            if (graph->hasSettlement(hasvertexSettlement)) {
                cout << "El vertice: " << hasvertexSettlement << " tiene un Asentamiento"<<endl;
            }
            else {
                    cout << "El vertice: " << hasvertexSettlement << " no Tiene un Asentamiento"<<endl;

            }

            system("pause");

            break;
        case 10:

            graph->buildCityOnVertex();
            system("pause");

            break;


        case 11:

            graph->buildCityOnVertex();
            system("pause");

            break;
        case 12:

            graph->buildRoadOnEdge();
            system("pause");

            break;
        case 13:

            graph->getRoadOnEdge();
            system("pause");

            break;
        case 14:

            graph->buildCityOnVertex();
            system("pause");

            break;










        case 0:
            system("pause");

            break;
        default:
            break;
        }
    }


    //Board menu;
    //menu.renderMenu();


        */

return 0;

}
