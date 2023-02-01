#include "Board.h"
#include "circle.h"
#include "BoardGraph.h"
#include "Construction.h"

#include <sstream>
#include<stdlib.h>
#include<time.h>
#include <dos.h>
#include <iostream>
#include <vector>
#include <list>
#include <windows.h>
#include <chrono>
#include <thread>
using namespace std::this_thread;

using namespace sf;
using namespace std;
Sprite sprite;
Sprite sprite2;
Sprite sprite3;
Sprite sprite4;

Texture texture;
Texture texture2;
Texture texture3;
Texture texture4;
ListCurrentPlayers currentPlayerList;
Event event;
const float RADIUS = 80;
vector<CircleShape> circlesBoard(100);
vector<bool> selectedCircle(100);
Circle c;
Construction Const;

bool vertFound = false;
int num = 0;
vector<Terrain*> terrains(20);
vector<Sprite> spriteTerrains(20);
vector<Texture> textureTerrains(20);

vector<Sprite> spriteImagesCards(6);
vector<Texture> textureImagesCards(6);

vector<Sprite> spriteImagesCards2(6);
vector<Texture> textureImagesCards2(6);

vector<Sprite> spriteImagesCards3(5);
vector<Texture> textureImagesCards3(5);

BoardGraph gph;

RectangleShape* transparentRectangles[18];
vector<Sprite> spritesImageDetection(17);
vector<Texture> texturedetection(17);

bool dicePlayer = false;//variable para saber si un jugador ya lanzo los dados
int diceRoll = 0;//variable para realizar una cantidad de veces el aleatorio de los dados
RectangleShape* rectangleDice1 = new RectangleShape({ 40,40 });//rectangulo para mostrar un dado
RectangleShape* rectangleDice2 = new RectangleShape({ 40,40 });//rectangulo para mostrar un dado

RectangleShape tradeRectangle({ 140,60 });//rectangulo de comercio
RectangleShape saveRectangle({ 140,60 });//rectangulo de guardar partida

Board::Board()
{

	GameWindow = new RenderWindow(VideoMode(1280, 720), "Game");
	
	reloj = new Clock();
	tiempo = new Time();

	font = new Font();
	font->loadFromFile("Chickenic.ttf");

	titlePlayers = new Text();
	titlePlayers->setFont(*font);
	titlePlayers->setString("Jugador: ");
	titlePlayers->setPosition({ 10,5 });
	titlePlayers->setCharacterSize(25);

	playersName = new Text();
	playersName->setFont(*font);
	playersName->setString(" ");
	playersName->setPosition({ 15,35 });
	playersName->setCharacterSize(25);

	x = new Text();
	x->setFont(*font);
	x->setString("x ");
	x->setCharacterSize(19);

	numberPlayersCardsWool = new Text();
	numberPlayersCardsWool->setFont(*font);
	numberPlayersCardsWool->setString(" 0");
	numberPlayersCardsWool->setCharacterSize(19);

	numberPlayersCardsClay = new Text();
	numberPlayersCardsClay->setFont(*font);
	numberPlayersCardsClay->setString(" 0");
	numberPlayersCardsClay->setCharacterSize(19);

	numberPlayersCardsWood = new Text();
	numberPlayersCardsWood->setFont(*font);
	numberPlayersCardsWood->setString(" 0");
	numberPlayersCardsWood->setCharacterSize(19);

	numberPlayersCardsStone = new Text();
	numberPlayersCardsStone->setFont(*font);
	numberPlayersCardsStone->setString(" 0");
	numberPlayersCardsStone->setCharacterSize(19);

	numberPlayersCardsWheat = new Text();
	numberPlayersCardsWheat->setFont(*font);
	numberPlayersCardsWheat->setString(" 0");
	numberPlayersCardsWheat->setCharacterSize(19);

	numberPlayersCardsKnight = new Text();
	numberPlayersCardsKnight->setFont(*font);
	numberPlayersCardsKnight->setString(" 0");
	numberPlayersCardsKnight->setCharacterSize(19);

	numberPlayersCardsArmy = new Text();
	numberPlayersCardsArmy->setFont(*font);
	numberPlayersCardsArmy->setString(" 0");
	numberPlayersCardsArmy->setCharacterSize(19);

	numberPlayersCardsRoute = new Text();
	numberPlayersCardsRoute->setFont(*font);
	numberPlayersCardsRoute->setString(" 0");
	numberPlayersCardsRoute->setCharacterSize(19);

	numberPlayersCardsRoad = new Text();
	numberPlayersCardsRoad->setFont(*font);
	numberPlayersCardsRoad->setString(" 0");
	numberPlayersCardsRoad->setCharacterSize(19);

	numberPlayersCardsInvention = new Text();
	numberPlayersCardsInvention->setFont(*font);
	numberPlayersCardsInvention->setString(" 0");
	numberPlayersCardsInvention->setCharacterSize(19);

	numberPlayersCardsMonopoly = new Text();
	numberPlayersCardsMonopoly->setFont(*font);
	numberPlayersCardsMonopoly->setString(" 0");
	numberPlayersCardsMonopoly->setCharacterSize(19);

	numberPlayersCardsTownHall = new Text();
	numberPlayersCardsTownHall->setFont(*font);
	numberPlayersCardsTownHall->setString(" 0");
	numberPlayersCardsTownHall->setCharacterSize(19);

	numberPlayersCardsLibrary = new Text();
	numberPlayersCardsLibrary->setFont(*font);
	numberPlayersCardsLibrary->setString(" 0");
	numberPlayersCardsLibrary->setCharacterSize(19);

	numberPlayersCardsChurch = new Text();
	numberPlayersCardsChurch->setFont(*font);
	numberPlayersCardsChurch->setString(" 0");
	numberPlayersCardsChurch->setCharacterSize(19);

	numberPlayersCardsMarket = new Text();
	numberPlayersCardsMarket->setFont(*font);
	numberPlayersCardsMarket->setString(" 0");
	numberPlayersCardsMarket->setCharacterSize(19);

	numberPlayersCardsUniversity = new Text();
	numberPlayersCardsUniversity->setFont(*font);
	numberPlayersCardsUniversity->setString(" 0");
	numberPlayersCardsUniversity->setCharacterSize(19);

	txtComercio = new Text();
	txtComercio->setFont(*font);
	txtComercio->setString("Comerciar");
	txtComercio->setCharacterSize(25);
	txtComercio->setPosition(1120, 630);

	txtSave = new Text();
	txtSave->setFont(*font);
	txtSave->setString("Guardar");
	txtSave->setCharacterSize(25);
	txtSave->setPosition(1130, 570);

	passTurn = new Event;

	/*RenderWindow window({1280, 720}, "Window");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();
		}



		window.display();
	}

	for (int i = 0; i < 4; i++) {
		optionsGame[i] = new RectangleShape({ 60,15 });
		optionsGame[i]->setFillColor(Color::Green);
	}

	optionsGame[0]->setPosition({ 70,170 });
	optionsGame[1]->setPosition({ 150,170 });
	optionsGame[2]->setPosition({ 70,210 });
	optionsGame[3]->setPosition({ 150,210 });
	renderGame();
	*/
}

void Board::drawCircles(vector<CircleShape> circles)
{
	int cont = 0;
	for (int i = 0; i < 37; i++) {
		GameWindow->draw(circles[cont]);
		cont++;
	}

}
void Board::generateTerrains() {


	ListTerrain* list = new ListTerrain();

	list->addTerrains();

	



	srand(time(NULL));

	for (int i = 0; i < 19; i++) {
		int num =  rand() % (6);
		cout <<"Numero del terreno: "<<num<<endl;
		Terrain* terrain = list->getTerrain(num);
		terrains[i] = list->getTerrain(num);
	}
	


	for (int i = 0; i < 19; i++) {

		cout<<"Terreno: "<<terrains[i]->getNameTerrain() << endl;

	}
	




}


void Board::loadImages() {
	for (int i = 0; i < 19; i++)
	{
		string pathImage = terrains[i]->getPathTerrain();
		texture.loadFromFile(pathImage);
		textureTerrains[i]=texture;
		cout << terrains[i]->getPathTerrain() << endl;
	}


	for (int i = 0; i < 19; i++)
	{

		cout << spriteTerrains[i].getTexture() << endl;



	}
	string vecImages1[6] = { "RECURSOS/CARTAS NUEVAS/TABLA-COSTES.png","RECURSOS/CARTAS NUEVAS/CARTA-ARCILLA.png","RECURSOS/CARTAS NUEVAS/CARTA-LANA.png","RECURSOS/CARTAS NUEVAS/CARTA-MADERA.png","RECURSOS/CARTAS NUEVAS/CARTA-ROCA.png","RECURSOS/CARTAS NUEVAS/CARTA-TRIGO.png"};
	string vecImages2[6] = { "RECURSOS/CARTAS NUEVAS/PROGRESO-MONOPOLIO.png","RECURSOS/CARTAS NUEVAS/PTS-AYUNTAMIENTO.png","RECURSOS/CARTAS NUEVAS/PTS-BIBLIOTECA.png","RECURSOS/CARTAS NUEVAS/PTS-IGLESIA.png","RECURSOS/CARTAS NUEVAS/PTS-MERCADO.png","RECURSOS/CARTAS NUEVAS/PTS-UNIVERSIDAD.png"};
	string vecImages3[5] = { "RECURSOS/CARTAS NUEVAS/PROGRESO-CARRETERA.png","RECURSOS/CARTAS NUEVAS/PROGRESO-INVENTO.png","RECURSOS/CARTAS NUEVAS/DESAROLLO-CABALLERO.png","RECURSOS/CARTAS NUEVAS/ESPECIAL-EJERCITO.png","RECURSOS/CARTAS NUEVAS/ESPECIAL-RUTA.png" };


	for (int i = 0; i < 6; i++) {
		string pathImageCard = vecImages1[i];
		texture2.loadFromFile(pathImageCard);
	    textureImagesCards[i] = texture2;
	}
	for (int i = 0; i < 6; i++) {
		string pathImageCard = vecImages2[i];
		texture3.loadFromFile(pathImageCard);
		textureImagesCards2[i] = texture3;
	}
	for (int i = 0; i < 5; i++) {
		string pathImageCard = vecImages3[i];
		texture4.loadFromFile(pathImageCard);
		textureImagesCards3[i] = texture4;
	}

	cout<<"Imagenes cargadas"<<endl;
}
void Board::renderTerrains()
{




		//cargar imagenes en un vector para no tener que cargarlas desde memoria 

		//createGameBoard();
		//selectTerrain();





		//cargar imagenes en un vector para no tener que cargarlas desde memoria 

		//createGameBoard();
		//selectTerrain();


	    float y = 70;
		float y2 = 70;
		float y3 = 70;
		for (int i = 0; i < 19; i++)
		{
			Sprite sprite(textureTerrains[i]);
			sprite.setScale(0.27f, 0.27f);
			if (i < 3)
				sprite.setPosition(505 + (i * 120), 55);
			if (i >= 3 && i < 7)
				sprite.setPosition(85 + (i * 120), 155);
			if (i >= 7 && i < 12)
				sprite.setPosition(-640+185 + (i * 120), 255);
			if (i >= 12 && i < 16)
				sprite.setPosition(-1225+230 + (i * 120), 355);
			if (i >= 16)
				sprite.setPosition(-1680+265 + (i * 120), 455);

			GameWindow->draw(sprite);
		}

		for (int i = 0; i < 6; i++)
		{
			Sprite spriteImagesCards(textureImagesCards[i]);
			spriteImagesCards.setScale(100.f / spriteImagesCards.getTexture()->getSize().x, 115.f / spriteImagesCards.getTexture()->getSize().y);
			spriteImagesCards.setPosition(5, y);

	
			terrains2 = terrains;

			y = y + 100;

			GameWindow->draw(spriteImagesCards);
		}
		for (int i = 0; i < 6; i++)
		{
			Sprite spriteImagesCards(textureImagesCards2[i]);
			spriteImagesCards.setScale(100.f / spriteImagesCards.getTexture()->getSize().x, 115.f / spriteImagesCards.getTexture()->getSize().y);
			spriteImagesCards.setPosition(120, y2);

			y2 = y2 + 100;

			GameWindow->draw(spriteImagesCards);
		}
		for (int i = 0; i < 5; i++)
		{
			Sprite spriteImagesCards(textureImagesCards3[i]);
			spriteImagesCards.setScale(100.f / spriteImagesCards.getTexture()->getSize().x, 115.f / spriteImagesCards.getTexture()->getSize().y);
			spriteImagesCards.setPosition(230, y3);

			y3 = y3 + 100;

			GameWindow->draw(spriteImagesCards);
		}


}

void Board::renderGame() {
	generateTerrains();
	loadImages();

	ListCurrentPlayers list;
	//Node* current;//prueba
	//current = list.First();

	//playersName->setString(current->player.getName());
	//current->player.getListPlayerCards().showList();


	while (GameWindow->isOpen()) {
		while (GameWindow->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				GameWindow->close();
		}
		//renderTerrains();
		createGameBoard();
		selectTerrain();
		GameWindow->display();

	}
}

void Board::buildTerrainOnVertexBoard() {


	BoardGraph bg;

	bg.generateBoard();
	bg.generateVertices();
	bg.generateRoadsEdges();

	for (int i = 0; i < 19; i++){
		bg.buildTerrainOnVertex(i+1, terrains[i]->getId());
	}

	for (int i = 0; i < 25; i++) {
		cout<<"Terreno en vertice: "<<i+1;
		if (bg.hasTerrain(i + 1) == true) {
			cout << " TRUE " << " Terreno: ";



			if (terrains[i]->getId() == bg.getTerrainVertex(i + 1)) {
				cout << terrains[i]->getNameTerrain() << endl;

			}

		}

		else
			cout << "FALSE";

		cout << endl;

	}
}


void Board::renderMenu(ListCurrentPlayers list)
{

	generateTerrains();
	loadImages();
	buildTerrainOnVertexBoard();
	gph.generateVertices();
	gph.generateRoadsEdges();
 

	paintTransparentRectangles();
 
	currentPlayerList = list;
 
	Node* currentP;//prueba
	currentP = list.First();
	Node* player = currentP;
	playersName->setString(currentP->player.getName());
	numberPlayersCardsWool->setString(to_string(countCards(currentP)[0]));
	numberPlayersCardsClay->setString(to_string(countCards(currentP)[1]));
	numberPlayersCardsWood->setString(to_string(countCards(currentP)[2]));
	numberPlayersCardsStone->setString(to_string(countCards(currentP)[3]));
	numberPlayersCardsWheat->setString(to_string(countCards(currentP)[4]));
	numberPlayersCardsMonopoly->setString(to_string(countCards(currentP)[5]));
	numberPlayersCardsTownHall->setString(to_string(countCards(currentP)[6]));
	numberPlayersCardsLibrary->setString(to_string(countCards(currentP)[7]));
	numberPlayersCardsChurch->setString(to_string(countCards(currentP)[8]));
	numberPlayersCardsMarket->setString(to_string(countCards(currentP)[9]));
	numberPlayersCardsUniversity->setString(to_string(countCards(currentP)[10]));
	numberPlayersCardsRoad->setString(to_string(countCards(currentP)[11]));
	numberPlayersCardsInvention->setString(to_string(countCards(currentP)[12]));
	numberPlayersCardsKnight->setString(to_string(countCards(currentP)[13]));
	numberPlayersCardsArmy->setString(to_string(countCards(currentP)[14]));
	numberPlayersCardsRoute->setString(to_string(countCards(currentP)[15]));
	
	while (GameWindow->isOpen()) {
	    positionMouse = Mouse::getPosition(*GameWindow);
		
		while (GameWindow->pollEvent(event)) {

			switch (event.type)
			{
			case Event::Closed:
				GameWindow->close();
				break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Enter)) {
					
					dicePlayer = false;
					diceRoll = 0;
					currentP = currentP->next;
					playersName->setString(currentP->player.getName());
					player = currentP;

					numberPlayersCardsWool->setString(to_string(countCards(currentP)[0]));
					numberPlayersCardsClay->setString(to_string(countCards(currentP)[1]));
					numberPlayersCardsWood->setString(to_string(countCards(currentP)[2]));
					numberPlayersCardsStone->setString(to_string(countCards(currentP)[3]));
					numberPlayersCardsWheat->setString(to_string(countCards(currentP)[4]));
					numberPlayersCardsMonopoly->setString(to_string(countCards(currentP)[5]));
					numberPlayersCardsTownHall->setString(to_string(countCards(currentP)[6]));
					numberPlayersCardsLibrary->setString(to_string(countCards(currentP)[7]));
					numberPlayersCardsChurch->setString(to_string(countCards(currentP)[8]));
					numberPlayersCardsMarket->setString(to_string(countCards(currentP)[9]));
					numberPlayersCardsUniversity->setString(to_string(countCards(currentP)[10]));
					numberPlayersCardsRoad->setString(to_string(countCards(currentP)[11]));
					numberPlayersCardsInvention->setString(to_string(countCards(currentP)[12]));
					numberPlayersCardsKnight->setString(to_string(countCards(currentP)[13]));
					numberPlayersCardsArmy->setString(to_string(countCards(currentP)[14]));
					numberPlayersCardsRoute->setString(to_string(countCards(currentP)[15]));
					
				}
				break;
			case Event::MouseButtonPressed:
				
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[0]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[0]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}
				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[1]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[1]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[2]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[2]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[3]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[3]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[4]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[4]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[5]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[5]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[6]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[6]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[7]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[7]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[8]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[8]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[9]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[9]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[10]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[10]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[11]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[11]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[12]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[12]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[13]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[13]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[14]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[14]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[15]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[15]);
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
						}
							window->clear();
							window->draw(s);
							window->display();
						
					}

				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[16]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					Sprite s(texturedetection[16]);
					int cc = 0;
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					while (window->isOpen()) {
						while (window->pollEvent(event)) {

							switch (event.type)
							{
							case Event::Closed:
								window->close();
								break;
							}
							
						}
						window->clear();
						window->draw(s);
						window->display();
						while (cc < 5000) {
							cc++;
						}
					}
					
				}
				if (Mouse::isButtonPressed(Mouse::Left) && transparentRectangles[17]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					dicePlayer = true;
					

				}
				if (Mouse::isButtonPressed(Mouse::Left) && tradeRectangle.getGlobalBounds().contains((Vector2f)positionMouse)) {
					system("cls");
					int op = 0;
					int opConfirm = 0;
					int cardsToGive = 0;
					int cardsToReceive = 0;
					int typeOfMaterialGive = 0;
					int typeOfMaterialReceive = 0;
					int contDeleteCards = 0;
					int contAddCards = 0;
					Node* otherPlayers = player->next;
					bool est = true;
					ListPlayerCards listAuxPlayer;
					ListPlayerCards listAuxOtherPlayers;
					do {
						system("cls");
						cout << "	------------------" << endl;
						cout << "	|    COMERCIO    |" << endl;
						cout << "	------------------" << endl;
						cout << "[ 1 = Lana, 2 = Arcilla, 3 = Madera, 4 = Mineral, 5 = Cereal ]" << endl << endl;
						cout << "Jugador: " << player->player.getName() << endl << endl;
						cout << "Materiales: Lana: " << countCards(player)[0] << " Madera: " << countCards(player)[2] << " Cereal: " << countCards(player)[4] << " Arcilla: " << countCards(player)[1] << " Mineral: " << countCards(player)[3] << endl << endl;

						cout << "1. Comerciar con otros jugadores." << endl << "2. Comerciar con el Banco." << endl << "Opcion: ";
						cin >> op;
					} while ((op != 1) && (op != 2));

					if (op == 1) {//comercio entre jugadores
						do {
							cout << endl;
							cout << "Que tipo de material quiero: " << endl; cin >> typeOfMaterialReceive;
						} while ((typeOfMaterialReceive != 1) && (typeOfMaterialReceive != 2) && (typeOfMaterialReceive != 3) && (typeOfMaterialReceive != 4) && (typeOfMaterialReceive != 5));
							
						cout << "Cuantas quiero: " << endl; cin >> cardsToReceive;
						do {
							cout << "Que tipo de material voy a dar: " << endl; cin >> typeOfMaterialGive;
						} while ((typeOfMaterialGive != 1) && (typeOfMaterialGive != 2) && (typeOfMaterialGive != 3) && (typeOfMaterialGive != 4) && (typeOfMaterialGive != 5));
							
						cout << "Cuantas voy a dar: " << endl; cin >> cardsToGive;
						if (typeOfMaterialGive == 1 && cardsToGive > countCards(player)[0]) {
							cout << "cartas insuficientes";
							cout << endl << "Vuelva al tablero pricipal!";
						}
						else if (typeOfMaterialGive == 2 && cardsToGive > countCards(player)[1]) {
							cout << "cartas insuficientes";
							cout << endl << "Vuelva al tablero pricipal!";
						}
						else if (typeOfMaterialGive == 3 && cardsToGive > countCards(player)[2]) {
							cout << "cartas insuficientes";
							cout << endl << "Vuelva al tablero pricipal!";
						}
						else if (typeOfMaterialGive == 4 && cardsToGive > countCards(player)[3]) {
							cout << "cartas insuficientes";
							cout << endl << "Vuelva al tablero pricipal!";
						}
						else if (typeOfMaterialGive == 5 && cardsToGive > countCards(player)[4]) {
							cout << "cartas insuficientes";
							cout << endl << "Vuelva al tablero pricipal!";
						}else {
							system("cls");
							cout << "Confirmar intercambio!" << endl << endl;

							while (est) {
								cout << "Jugardor: " << otherPlayers->player.getName() << " Acepta el intercambio de cartas? (1 = Si, 2 = No): "; cin >> opConfirm;
								if ((opConfirm == 1) && (countCards(otherPlayers)[typeOfMaterialReceive - 1] > cardsToReceive)) {
									while (contDeleteCards < cardsToGive) {
										listAuxPlayer = player->player.getListPlayerCards();
										listAuxPlayer.deleteCard(typeOfMaterialGive);
										player->player.setListCards(listAuxPlayer);

										listAuxOtherPlayers = otherPlayers->player.getListPlayerCards();
										listAuxOtherPlayers.addCard(typeOfMaterialGive);
										otherPlayers->player.setListCards(listAuxOtherPlayers);

										contDeleteCards++;
									}
									while (contAddCards < cardsToReceive) {
										listAuxPlayer = player->player.getListPlayerCards();
										listAuxPlayer.addCard(typeOfMaterialReceive);
										player->player.setListCards(listAuxPlayer);

										listAuxOtherPlayers = otherPlayers->player.getListPlayerCards();
										listAuxOtherPlayers.deleteCard(typeOfMaterialReceive);
										otherPlayers->player.setListCards(listAuxOtherPlayers);

										contAddCards++;
									}
									cout << endl << "==> Intercambio Exitoso! <==" << endl;
									system("pause");
									est = false;
								}
								else {
									if (opConfirm != 2) {
										cout << endl << otherPlayers->player.getName() << " no cuenta con la cantidad necesaria de materiales para intercambiar!" << endl;
										system("pause");
									}
									otherPlayers = otherPlayers->next;
									if(otherPlayers == player)
										est = false;
									system("cls");
								}
							}
							system("cls");
							cout << "Vuelva al tablero pricipal!";
						}
					}

					if (op == 2) {//comercio con el banco
						int materialToChange = 0;
						int materialToReceive = 0;
						int cont1 = 0;						

						cout << endl << endl;
						cout << " La manera de comerciar con el banco es de 4:1. Se dan 4 cartas y se recibe una." << endl << endl;
						do {
							cout << "1 - Lana" << endl << "2 - Arcilla" << endl << "3 - Madera" << endl << "4 - Mineral" << endl << "5 - Cereal" << endl;
							cout << "Elija que material desea recibir: "; cin >> materialToReceive;
						} while ((materialToReceive != 1) && (materialToReceive != 2) && (materialToReceive != 3) && (materialToReceive != 4) && (materialToReceive != 5));
						do{
							cout << endl;
							cout << "1 - Lana" << endl << "2 - Arcilla" << endl << "3 - Madera" << endl << "4 - Mineral" << endl << "5 - Cereal" << endl;
							cout << "Elija que material desea dar: "; cin >> materialToChange;
						} while ((materialToChange != 1) && (materialToChange != 2) && (materialToChange != 3) && (materialToChange != 4) && (materialToChange != 5));

						cout << endl << endl;
						if (countCards(player)[materialToChange-1] < 4) {
							system("cls");
							cout << "No cuentas con la cantidad suficiente de este material para intercambiar!" << endl;
							cout << "Vuelva al tablero pricipal!" << endl;
							system("pause");
						}
						else {
							listAuxPlayer = player->player.getListPlayerCards();
							listAuxPlayer.addCard(materialToReceive);
							while (cont1 < 4) {

								listAuxPlayer.deleteCard(materialToChange);
								player->player.setListCards(listAuxPlayer);

								cont1++;
							} 
							system("cls");
							cout << endl << "==> Intercambio Exitoso! <==" << endl << endl;
							cout << "Vuelva al tablero pricipal!";
							system("pause");
						}
					}

					//GameWindow->setActive(false);
				}
				if (Mouse::isButtonPressed(Mouse::Left) && saveRectangle.getGlobalBounds().contains((Vector2f)positionMouse)) {

				}
				break;
			}
		}
		GameWindow->clear(sf::Color::Black);
		renderTerrains();
		
		paintFixedElements();
		GameWindow->draw(*playersName);
		createGameBoard();
 
		//paintSettlemetsOnBoard();
 
		paintSettlemetsOnBoard();
		paintCityOnBoard();
		paintRoadsOnBoard();
		selectTerrain();
		if (diceRoll < 100 && dicePlayer == true) {
			
			cout <<" SUMA DE VALORES DE LOS DADOS "<< dices();
			diceRoll++;
		}
		//createGameBoard();
		
		GameWindow->display();

	}
	
}


void Board::paintFixedElements()//pinta los labels y recuadros
{
	float y = 210;
	float y2 = 110;
	float y3 = 110;
	RectangleShape currentPlayer({ 200,60 });
	currentPlayer.setPosition({ 10,10 });
	currentPlayer.setFillColor(Color::Blue);

	saveRectangle.setPosition(1110, 555);
	saveRectangle.setFillColor(Color::Blue);

	tradeRectangle.setPosition({ 1110,620 });
	tradeRectangle.setFillColor(Color::Blue);

	for (int i = 0; i < 5; i++) {

		x->setPosition({90,y});
	    numberPlayersCardsWool->setPosition({ 100,310 });
		numberPlayersCardsClay->setPosition({ 100,210 });
		numberPlayersCardsWood->setPosition({ 100,410 });
		numberPlayersCardsStone->setPosition({ 100,510 });
		numberPlayersCardsWheat->setPosition({ 100,610 });

		GameWindow->draw(*numberPlayersCardsWool);
		GameWindow->draw(*numberPlayersCardsClay);
		GameWindow->draw(*numberPlayersCardsWood);
		GameWindow->draw(*numberPlayersCardsStone);
		GameWindow->draw(*numberPlayersCardsWheat);
		GameWindow->draw(*x);
		y = y + 100;
	}
	for (int i = 0; i < 6; i++) {

		x->setPosition({ 200,y2 });
		numberPlayersCardsMonopoly->setPosition({ 210,110 });
		numberPlayersCardsTownHall->setPosition({ 210,210 });
		numberPlayersCardsLibrary->setPosition({ 210,310 });
		numberPlayersCardsChurch->setPosition({ 210,410 });
		numberPlayersCardsMarket->setPosition({ 210,510 });
		numberPlayersCardsUniversity->setPosition({ 210,610 });

		GameWindow->draw(*numberPlayersCardsMonopoly);
		GameWindow->draw(*numberPlayersCardsTownHall);
		GameWindow->draw(*numberPlayersCardsUniversity);
		GameWindow->draw(*numberPlayersCardsChurch);
		GameWindow->draw(*numberPlayersCardsMarket);
		GameWindow->draw(*numberPlayersCardsLibrary);
		GameWindow->draw(*x);
		y2 = y2 + 100;
	}
	for (int i = 0; i < 5; i++) {

		x->setPosition({ 310,y3 });
		numberPlayersCardsRoad->setPosition({ 320,110 });
		numberPlayersCardsInvention->setPosition({ 320,210 });
		numberPlayersCardsKnight->setPosition({ 320,310 });
		numberPlayersCardsArmy->setPosition({ 320,410 });
		numberPlayersCardsRoute->setPosition({ 320,510 });

		GameWindow->draw(*numberPlayersCardsRoad);
		GameWindow->draw(*numberPlayersCardsInvention);
		GameWindow->draw(*numberPlayersCardsKnight);
		GameWindow->draw(*numberPlayersCardsArmy);
		GameWindow->draw(*numberPlayersCardsRoute);

		GameWindow->draw(*x);
		y3 = y3 + 100;
	}

	GameWindow->draw(currentPlayer);
	GameWindow->draw(tradeRectangle);
	GameWindow->draw(saveRectangle);
	GameWindow->draw(*titlePlayers);
	GameWindow->draw(*txtComercio);
	GameWindow->draw(*txtSave);

	rectangleDice1->setPosition(260, 590);
	rectangleDice2->setPosition(260, 632);
	

	GameWindow->draw(*rectangleDice1);
	GameWindow->draw(*rectangleDice2);

}

void Board::paintCards()
{



}

vector<int> Board::countCards(Node* nodePlayer)
{
	vector<int> vecCards(17);

	ListPlayerCards list;
	list = nodePlayer->player.getListPlayerCards();

	NodeCard* aux;
	aux = list.First();
	while (aux != NULL) {
//posiciones del vector [lana, arcilla, madera, roca, trigo, monopolio, ayuntamiento, biblioteca, iglesia, mercado, universidad, carretera, invento, caballero, mayorEjercito, mayorRuta]
		if (aux->card.getIdCard() == 1) {
			vecCards[0] = vecCards[0] + 1;			
		}
		if (aux->card.getIdCard() == 2) {
			vecCards[1] = vecCards[1] + 1;
		}
		if (aux->card.getIdCard() == 3) {
			vecCards[2] = vecCards[2] + 1;
		}
		if (aux->card.getIdCard() == 4) {
			vecCards[3] = vecCards[3] + 1;
		}
		if (aux->card.getIdCard() == 5) {
			vecCards[4] = vecCards[4] + 1;
		}
		if (aux->card.getIdCard() == 6) {
			vecCards[5] = vecCards[5] + 1;
		}
		if (aux->card.getIdCard() == 7) {
			vecCards[6] = vecCards[6] + 1;
		}
		if (aux->card.getIdCard() == 8) {
			vecCards[7] = vecCards[7] + 1;
		}
		if (aux->card.getIdCard() == 9) {
			vecCards[8] = vecCards[8] + 1;
		}
		if (aux->card.getIdCard() == 10) {
			vecCards[9] = vecCards[9] + 1;
		}
		if (aux->card.getIdCard() == 11) {
			vecCards[10] = vecCards[10] + 1;
		}
		if (aux->card.getIdCard() == 12) {
			vecCards[11] = vecCards[11] + 1;
		}
		if (aux->card.getIdCard() == 13) {
			vecCards[12] = vecCards[12] + 1;
		}
		if (aux->card.getIdCard() == 14) {
			vecCards[13] = vecCards[13] + 1;
		}
		if (aux->card.getIdCard() == 15) {
			vecCards[14] = vecCards[14] + 1;
		}
		if (aux->card.getIdCard() == 16) {
			vecCards[15] = vecCards[15] + 1;
		}
		if (aux->next != NULL) {
			aux = aux->next;
		}
		else {
			aux = NULL;
		}
	}
	return vecCards;
}

void Board::paintTransparentRectangles()
{
	Texture* t1 = new Texture();
	t1->loadFromFile("RECURSOS/DADOS/dado1.png");
	rectangleDice1->setTexture(t1);
	rectangleDice2->setTexture(t1);

	string vectorCardsImages[17]{ "RECURSOS/CARTAS GRANDES/TABLA-COSTES.png","RECURSOS/CARTAS GRANDES/CARTA-ARCILLA.png","RECURSOS/CARTAS GRANDES/CARTA-LANA.png","RECURSOS/CARTAS GRANDES/CARTA-MADERA.png","RECURSOS/CARTAS GRANDES/CARTA-ROCA.png","RECURSOS/CARTAS GRANDES/CARTA-TRIGO.png","RECURSOS/CARTAS GRANDES/PROGRESO-MONOPOLIO.png","RECURSOS/CARTAS GRANDES/PTS-AYUNTAMIENTO.png","RECURSOS/CARTAS GRANDES/PTS-BIBLIOTECA.png","RECURSOS/CARTAS GRANDES/PTS-IGLESIA.png","RECURSOS/CARTAS GRANDES/PTS-MERCADO.png","RECURSOS/CARTAS GRANDES/PTS-UNIVERSIDAD.png"
	,"RECURSOS/CARTAS GRANDES/PROGRESO-CARRETERA.png","RECURSOS/CARTAS GRANDES/PROGRESO-INVENTO.png","RECURSOS/CARTAS GRANDES/DESAROLLO-CABALLERO.png","RECURSOS/CARTAS GRANDES/ESPECIAL-EJERCITO.png","RECURSOS/CARTAS GRANDES/ESPECIAL-RUTA.png" };
	
	
	float x = 20;
	float y = 80;
	for (int i = 0; i < 17; i++) {
		if (i == 6) {
			x = 130;
			y = 80;
		}
		if (i == 12) {
			x = 240;
			y = 80;
		}

		transparentRectangles[i] = new RectangleShape({ 70,95 });
		transparentRectangles[i]->setFillColor(Color::Yellow);
		transparentRectangles[i]->setPosition({ x,y });
		GameWindow->draw(*transparentRectangles[i]);
		y = y + 100;
		string path = vectorCardsImages[i];
		texturedetection[i].loadFromFile(path);
		
	}
	transparentRectangles[17] = new RectangleShape({ 70,95 });
	transparentRectangles[17]->setFillColor(Color::Yellow);
	transparentRectangles[17]->setPosition({ x,y });
	
	GameWindow->draw(*transparentRectangles[17]);
	GameWindow->draw(*rectangleDice1);
	GameWindow->draw(*rectangleDice2);
}


int Board::dices()
{
	int num = 0;
	int num2 = 0;

	Texture* texture = new Texture();
	Texture* texture2 = new Texture();
	string vecDices[6]{ "RECURSOS/DADOS/dado1.png","RECURSOS/DADOS/dado2.png","RECURSOS/DADOS/dado3.png","RECURSOS/DADOS/dado4.png","RECURSOS/DADOS/dado5.png","RECURSOS/DADOS/dado6.png" };
	RectangleShape* rectangle1 = new RectangleShape({ 40,40 });
	RectangleShape* rectangle2 = new RectangleShape({ 40,40 });
	//for (int i = 0; i < 305; i++) {
	num = rand() % 6;
	texture->loadFromFile(vecDices[num]);
	rectangle1->setTexture(texture);
	rectangle1->setPosition(260, 590);
	GameWindow->draw(*rectangle1);

	num2 = rand() % 6;
	texture2->loadFromFile(vecDices[num2]);
	rectangle2->setTexture(texture);
	rectangle2->setPosition(260, 632);
	GameWindow->draw(*rectangle2);


	if (diceRoll == 99) {
		rectangleDice1->setTexture(texture);
		rectangleDice2->setTexture(texture2);
	}
	//}
	return (num + 1) + (num2 + 1) ;
	

}
int Board::currentPlayer(string nameCurrentPlayer)
{
	int cont = 0;



	Node* player;
	player = currentPlayerList.First();

	while (player != NULL) {
			if (player->PlayerName().getName() == nameCurrentPlayer) {
				return cont;
			}
			cont++;

	
		player = player->next;

	}




	return -1;
}

void Board::paintSettlemetsOnBoard()
{
	int Player = -1;
	if (gph.hasSettlement(20)) {
		Player = gph.getVertex(20)->player;


		CircleShape circleSegment = Const.renderSettlement(circlesBoard[0].getPosition().x + 60, circlesBoard[0].getPosition().y + 30, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(21)) {
		Player = gph.getVertex(21)->player;

		CircleShape circleSegment = Const.renderSettlement(circlesBoard[1].getPosition().x + 60, circlesBoard[1].getPosition().y + 30, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(22)) {
		Player = gph.getVertex(22)->player;

		CircleShape circleSegment = Const.renderSettlement(circlesBoard[2].getPosition().x + 60, circlesBoard[2].getPosition().y + 30, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(23)) {
		Player = gph.getVertex(23)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[0].getPosition().x - 5, circlesBoard[0].getPosition().y + 56, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(24)) {
		Player = gph.getVertex(24)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[1].getPosition().x - 5, circlesBoard[0].getPosition().y + 56, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(25)) {
		Player = gph.getVertex(25)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[2].getPosition().x - 5, circlesBoard[0].getPosition().y + 56, 10, Player);
		GameWindow->draw(circleSegment);

	}
	if (gph.hasSettlement(26)) {
		Player = gph.getVertex(26)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[3].getPosition().x - 5, circlesBoard[0].getPosition().y + 56, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(27)) {
		Player = gph.getVertex(27)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[4].getPosition().x + 60, circlesBoard[4].getPosition().y + 40, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(28)) {
		Player = gph.getVertex(28)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[5].getPosition().x + 60, circlesBoard[5].getPosition().y + 40, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(29)) {
		Player = gph.getVertex(29)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[6].getPosition().x + 60, circlesBoard[6].getPosition().y + 40, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(30)) {
		Player = gph.getVertex(30)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[7].getPosition().x + 60, circlesBoard[7].getPosition().y + 40, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(31)) {
		Player = gph.getVertex(31)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[4].getPosition().x, circlesBoard[4].getPosition().y + 70, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(32)) {
		Player = gph.getVertex(32)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[5].getPosition().x, circlesBoard[5].getPosition().y + 70, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(33)) {
		Player = gph.getVertex(33)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[6].getPosition().x, circlesBoard[6].getPosition().y + 70, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(34)) {
		Player = gph.getVertex(34)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[7].getPosition().x, circlesBoard[7].getPosition().y + 70, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(35)) {
		Player = gph.getVertex(35)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[8].getPosition().x, circlesBoard[8].getPosition().y + 70, 10, Player);
		GameWindow->draw(circleSegment);
	}


	if (gph.hasSettlement(36)) {
		Player = gph.getVertex(36)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[9].getPosition().x + 60, circlesBoard[9].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(37)) {
		Player = gph.getVertex(37)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[10].getPosition().x + 60, circlesBoard[10].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(38)) {
		Player = gph.getVertex(38)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[11].getPosition().x + 60, circlesBoard[11].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(39)) {
		Player = gph.getVertex(39)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[12].getPosition().x + 60, circlesBoard[12].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(40)) {
		Player = gph.getVertex(40)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[13].getPosition().x + 60, circlesBoard[13].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}


	if (gph.hasSettlement(41)) {
		Player = gph.getVertex(41)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[9].getPosition().x + 3, circlesBoard[9].getPosition().y + 65, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(42)) {
		Player = gph.getVertex(42)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[10].getPosition().x + 3, circlesBoard[10].getPosition().y + 65, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(43)) {
		Player = gph.getVertex(43)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[11].getPosition().x + 3, circlesBoard[11].getPosition().y + 65, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(44)) {
		Player = gph.getVertex(44)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[12].getPosition().x + 3, circlesBoard[12].getPosition().y + 65, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(45)) {
		Player = gph.getVertex(45)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[13].getPosition().x + 3, circlesBoard[13].getPosition().y + 65, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(46)) {
		Player = gph.getVertex(46)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[14].getPosition().x + 3, circlesBoard[14].getPosition().y + 65, 10, Player);
		GameWindow->draw(circleSegment);
	}


	if (gph.hasSettlement(47)) {
		Player = gph.getVertex(47)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[15].getPosition().x + 65, circlesBoard[15].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(48)) {
		Player = gph.getVertex(48)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[16].getPosition().x + 65, circlesBoard[16].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(49)) {
		Player = gph.getVertex(49)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[17].getPosition().x + 65, circlesBoard[17].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(50)) {
		Player = gph.getVertex(50)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[18].getPosition().x + 65, circlesBoard[18].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(51)) {
		Player = gph.getVertex(51)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[19].getPosition().x + 65, circlesBoard[19].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(52)) {
		Player = gph.getVertex(52)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[20].getPosition().x + 65, circlesBoard[20].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}



	if (gph.hasSettlement(53)) {
		Player = gph.getVertex(53)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[16].getPosition().x + 5, circlesBoard[16].getPosition().y + 73, 10, Player);
		GameWindow->draw(circleSegment);
	}

	if (gph.hasSettlement(54)) {
		Player = gph.getVertex(54)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[17].getPosition().x + 5, circlesBoard[17].getPosition().y + 73, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(55)) {
		Player = gph.getVertex(55)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[18].getPosition().x + 5, circlesBoard[18].getPosition().y + 73, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(56)) {
		Player = gph.getVertex(56)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[19].getPosition().x + 5, circlesBoard[19].getPosition().y + 73, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(57)) {
		Player = gph.getVertex(57)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[20].getPosition().x + 5, circlesBoard[20].getPosition().y + 73, 10, Player);
		GameWindow->draw(circleSegment);
	}


	if (gph.hasSettlement(58)) {
		Player = gph.getVertex(58)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[22].getPosition().x + 60, circlesBoard[22].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(59)) {
		Player = gph.getVertex(59)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[23].getPosition().x + 60, circlesBoard[22].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(60)) {
		Player = gph.getVertex(60)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[24].getPosition().x + 60, circlesBoard[22].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(61)) {
		Player = gph.getVertex(61)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[25].getPosition().x + 60, circlesBoard[22].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(62)) {
		Player = gph.getVertex(62)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[26].getPosition().x + 60, circlesBoard[22].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}



	if (gph.hasSettlement(63)) {
		Player = gph.getVertex(63)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[23].getPosition().x + 2, circlesBoard[23].getPosition().y + 66, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(64)) {
		Player = gph.getVertex(64)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[24].getPosition().x + 2, circlesBoard[24].getPosition().y + 66, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(65)) {
		Player = gph.getVertex(65)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[25].getPosition().x + 2, circlesBoard[25].getPosition().y + 66, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(66)) {
		Player = gph.getVertex(66)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[26].getPosition().x + 2, circlesBoard[26].getPosition().y + 66, 10, Player);
		GameWindow->draw(circleSegment);
	}


	if (gph.hasSettlement(67)) {
		Player = gph.getVertex(67)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[28].getPosition().x + 60, circlesBoard[28].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(68)) {
		Player = gph.getVertex(68)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[29].getPosition().x + 60, circlesBoard[29].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(69)) {
		Player = gph.getVertex(69)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[30].getPosition().x + 60, circlesBoard[30].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(70)) {
		Player = gph.getVertex(70)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[31].getPosition().x + 60, circlesBoard[31].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}





	if (gph.hasSettlement(71)) {
		Player = gph.getVertex(71)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[29].getPosition().x + 2, circlesBoard[29].getPosition().y + 66, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(72)) {
		Player = gph.getVertex(72)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[30].getPosition().x + 2, circlesBoard[30].getPosition().y + 66, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasSettlement(73)) {
		Player = gph.getVertex(73)->player;
		CircleShape circleSegment = Const.renderSettlement(circlesBoard[31].getPosition().x + 2, circlesBoard[31].getPosition().y + 66, 10, Player);
		GameWindow->draw(circleSegment);
	}

 

}

void Board::createGameBoard()
{
	Circle c;
	c.drawCirclesBackground();
	drawCircles(c.drawCirclesBackground());

}

void Board::paintCityOnBoard()
{

	int Player = -1;


	if (gph.hasCity(20)) {
		Player = gph.getVertex(20)->player;


		CircleShape circleSegment = Const.renderCity(circlesBoard[0].getPosition().x + 60, circlesBoard[0].getPosition().y + 30, 10, Player);
		GameWindow->draw(circleSegment);
	}



	if (gph.hasCity(21)) {
		Player = gph.getVertex(21)->player;

		CircleShape circleSegment = Const.renderCity(circlesBoard[1].getPosition().x + 60, circlesBoard[1].getPosition().y + 30, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(22)) {
		Player = gph.getVertex(22)->player;

		CircleShape circleSegment = Const.renderCity(circlesBoard[2].getPosition().x + 60, circlesBoard[2].getPosition().y + 30, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(23)) {
		Player = gph.getVertex(23)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[0].getPosition().x - 5, circlesBoard[0].getPosition().y + 56, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(24)) {
		Player = gph.getVertex(24)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[1].getPosition().x - 5, circlesBoard[0].getPosition().y + 56, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(25)) {
		Player = gph.getVertex(25)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[2].getPosition().x - 5, circlesBoard[0].getPosition().y + 56, 10, Player);
		GameWindow->draw(circleSegment);

	}
	if (gph.hasCity(26)) {
		Player = gph.getVertex(26)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[3].getPosition().x - 5, circlesBoard[0].getPosition().y + 56, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(27)) {
		Player = gph.getVertex(27)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[4].getPosition().x + 60, circlesBoard[4].getPosition().y + 40, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(28)) {
		Player = gph.getVertex(28)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[5].getPosition().x + 60, circlesBoard[5].getPosition().y + 40, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(29)) {
		Player = gph.getVertex(29)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[6].getPosition().x + 60, circlesBoard[6].getPosition().y + 40, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(30)) {
		Player = gph.getVertex(30)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[7].getPosition().x + 60, circlesBoard[7].getPosition().y + 40, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(31)) {
		Player = gph.getVertex(31)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[4].getPosition().x, circlesBoard[4].getPosition().y + 70, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(32)) {
		Player = gph.getVertex(32)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[5].getPosition().x, circlesBoard[5].getPosition().y + 70, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(33)) {
		Player = gph.getVertex(33)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[6].getPosition().x, circlesBoard[6].getPosition().y + 70, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(34)) {
		Player = gph.getVertex(34)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[7].getPosition().x, circlesBoard[7].getPosition().y + 70, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(35)) {
		Player = gph.getVertex(35)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[8].getPosition().x, circlesBoard[8].getPosition().y + 70, 10, Player);
		GameWindow->draw(circleSegment);
	}


	if (gph.hasCity(36)) {
		Player = gph.getVertex(36)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[9].getPosition().x + 60, circlesBoard[9].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(37)) {
		Player = gph.getVertex(37)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[10].getPosition().x + 60, circlesBoard[10].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(38)) {
		Player = gph.getVertex(38)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[11].getPosition().x + 60, circlesBoard[11].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(39)) {
		Player = gph.getVertex(39)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[12].getPosition().x + 60, circlesBoard[12].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(40)) {
		Player = gph.getVertex(40)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[13].getPosition().x + 60, circlesBoard[13].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}


	if (gph.hasCity(41)) {
		Player = gph.getVertex(41)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[9].getPosition().x + 3, circlesBoard[9].getPosition().y + 65, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(42)) {
		Player = gph.getVertex(42)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[10].getPosition().x + 3, circlesBoard[10].getPosition().y + 65, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(43)) {
		Player = gph.getVertex(43)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[11].getPosition().x + 3, circlesBoard[11].getPosition().y + 65, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(44)) {
		Player = gph.getVertex(44)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[12].getPosition().x + 3, circlesBoard[12].getPosition().y + 65, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(45)) {
		Player = gph.getVertex(45)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[13].getPosition().x + 3, circlesBoard[13].getPosition().y + 65, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(46)) {
		Player = gph.getVertex(46)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[14].getPosition().x + 3, circlesBoard[14].getPosition().y + 65, 10, Player);
		GameWindow->draw(circleSegment);
	}


	if (gph.hasCity(47)) {
		Player = gph.getVertex(47)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[15].getPosition().x + 65, circlesBoard[15].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(48)) {
		Player = gph.getVertex(48)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[16].getPosition().x + 65, circlesBoard[16].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(49)) {
		Player = gph.getVertex(49)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[17].getPosition().x + 65, circlesBoard[17].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(50)) {
		Player = gph.getVertex(50)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[18].getPosition().x + 65, circlesBoard[18].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(51)) {
		Player = gph.getVertex(51)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[19].getPosition().x + 65, circlesBoard[19].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(52)) {
		Player = gph.getVertex(52)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[20].getPosition().x + 65, circlesBoard[20].getPosition().y + 35, 10, Player);
		GameWindow->draw(circleSegment);
	}



	if (gph.hasCity(53)) {
		Player = gph.getVertex(53)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[16].getPosition().x + 5, circlesBoard[16].getPosition().y + 73, 10, Player);
		GameWindow->draw(circleSegment);
	}

	if (gph.hasCity(54)) {
		Player = gph.getVertex(54)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[17].getPosition().x + 5, circlesBoard[17].getPosition().y + 73, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(55)) {
		Player = gph.getVertex(55)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[18].getPosition().x + 5, circlesBoard[18].getPosition().y + 73, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(56)) {
		Player = gph.getVertex(56)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[19].getPosition().x + 5, circlesBoard[19].getPosition().y + 73, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(57)) {
		Player = gph.getVertex(57)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[20].getPosition().x + 5, circlesBoard[20].getPosition().y + 73, 10, Player);
		GameWindow->draw(circleSegment);
	}


	if (gph.hasCity(58)) {
		Player = gph.getVertex(58)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[22].getPosition().x + 60, circlesBoard[22].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(59)) {
		Player = gph.getVertex(59)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[23].getPosition().x + 60, circlesBoard[22].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(60)) {
		Player = gph.getVertex(60)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[24].getPosition().x + 60, circlesBoard[22].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(61)) {
		Player = gph.getVertex(61)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[25].getPosition().x + 60, circlesBoard[22].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(62)) {
		Player = gph.getVertex(62)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[26].getPosition().x + 60, circlesBoard[22].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}



	if (gph.hasCity(63)) {
		Player = gph.getVertex(63)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[23].getPosition().x + 2, circlesBoard[23].getPosition().y + 66, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(64)) {
		Player = gph.getVertex(64)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[24].getPosition().x + 2, circlesBoard[24].getPosition().y + 66, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(65)) {
		Player = gph.getVertex(65)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[25].getPosition().x + 2, circlesBoard[25].getPosition().y + 66, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(66)) {
		Player = gph.getVertex(66)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[26].getPosition().x + 2, circlesBoard[26].getPosition().y + 66, 10, Player);
		GameWindow->draw(circleSegment);
	}


	if (gph.hasCity(67)) {
		Player = gph.getVertex(67)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[28].getPosition().x + 60, circlesBoard[28].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(68)) {
		Player = gph.getVertex(68)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[29].getPosition().x + 60, circlesBoard[29].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(69)) {
		Player = gph.getVertex(69)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[30].getPosition().x + 60, circlesBoard[30].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(70)) {
		Player = gph.getVertex(70)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[31].getPosition().x + 60, circlesBoard[31].getPosition().y + 32, 10, Player);
		GameWindow->draw(circleSegment);
	}





	if (gph.hasCity(71)) {
		Player = gph.getVertex(71)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[29].getPosition().x + 2, circlesBoard[29].getPosition().y + 66, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(72)) {
		Player = gph.getVertex(72)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[30].getPosition().x + 2, circlesBoard[30].getPosition().y + 66, 10, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasCity(73)) {
		Player = gph.getVertex(73)->player;
		CircleShape circleSegment = Const.renderCity(circlesBoard[31].getPosition().x + 2, circlesBoard[31].getPosition().y + 66, 10, Player);
		GameWindow->draw(circleSegment);
	}



}


void Board::paintVerticalRoads() {

	BoardEdge* edge;

	int Player = -1;

	if (gph.hasRoad(gph.getEdge(23, 27))) {
		Player = gph.getEdge(23, 27)->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[4].getPosition().x + 71, circlesBoard[4].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasRoad(gph.getEdge(24, 28))) {
		Player = gph.getEdge(24, 28)->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[5].getPosition().x + 72, circlesBoard[5].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	if (gph.hasRoad(gph.getEdge(25, 29))) {
		Player = gph.getEdge(24, 28)->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[6].getPosition().x + 71, circlesBoard[6].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(26, 30);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[7].getPosition().x + 71, circlesBoard[7].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	//-----------




	edge = gph.getEdge(31, 36);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[9].getPosition().x + 71, circlesBoard[9].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(32, 37);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[10].getPosition().x + 71, circlesBoard[10].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(33, 38);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[11].getPosition().x + 71, circlesBoard[11].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(34, 39);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[12].getPosition().x + 71, circlesBoard[12].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(35, 40);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[13].getPosition().x + 71, circlesBoard[13].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}





	//-----------


	edge = gph.getEdge(41, 47);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[15].getPosition().x + 71, circlesBoard[15].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(42, 48);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[16].getPosition().x + 71, circlesBoard[16].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(43, 49);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[17].getPosition().x + 71, circlesBoard[17].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(44, 50);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[18].getPosition().x + 71, circlesBoard[18].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(45, 51);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[19].getPosition().x + 71, circlesBoard[19].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(46, 52);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[20].getPosition().x + 71, circlesBoard[20].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}



	//-----------


	edge = gph.getEdge(53, 58);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[22].getPosition().x + 71, circlesBoard[22].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(54, 59);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[23].getPosition().x + 71, circlesBoard[23].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(55, 60);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[24].getPosition().x + 71, circlesBoard[24].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(56, 61);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[25].getPosition().x + 71, circlesBoard[25].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(57, 62);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[26].getPosition().x + 71, circlesBoard[26].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}


	//----------


	edge = gph.getEdge(63, 67);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[28].getPosition().x + 71, circlesBoard[28].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(64, 68);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[29].getPosition().x + 71, circlesBoard[29].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(65, 69);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[30].getPosition().x + 71, circlesBoard[30].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(66, 70);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderVecticalRoad(circlesBoard[31].getPosition().x + 71, circlesBoard[31].getPosition().y - 12, Player);
		GameWindow->draw(circleSegment);
	}



}

void Board::paintDiagonalRightRoads()
{




	BoardEdge* edge;

	int Player = -1;


	edge = gph.getEdge(20, 24);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[0].getPosition().x + 93, circlesBoard[0].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}


	edge = gph.getEdge(21, 25);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[1].getPosition().x + 93, circlesBoard[1].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(22, 26);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[2].getPosition().x + 93, circlesBoard[2].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}



	//--------
	edge = gph.getEdge(27, 32);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[4].getPosition().x + 93, circlesBoard[4].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(28, 33);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[5].getPosition().x + 93, circlesBoard[5].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(29, 34);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[6].getPosition().x + 93, circlesBoard[6].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(30, 35);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[7].getPosition().x + 93, circlesBoard[7].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}


	//----------

	edge = gph.getEdge(36, 42);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[9].getPosition().x + 93, circlesBoard[9].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(37, 43);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[10].getPosition().x + 93, circlesBoard[10].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(38, 44);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[11].getPosition().x + 93, circlesBoard[11].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(39, 45);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[12].getPosition().x + 93, circlesBoard[12].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(40, 46);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[13].getPosition().x + 93, circlesBoard[13].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}


	//---------

	edge = gph.getEdge(47, 53);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[16].getPosition().x-18, circlesBoard[16].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(48, 54);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[17].getPosition().x -18, circlesBoard[17].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(49, 55);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[18].getPosition().x -18, circlesBoard[18].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(50, 56);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[19].getPosition().x -18, circlesBoard[19].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(51, 57);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[20].getPosition().x -18, circlesBoard[20].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}


	//-----------


	edge = gph.getEdge(58, 63);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[23].getPosition().x -18, circlesBoard[23].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}


	edge = gph.getEdge(59, 64);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[24].getPosition().x -18, circlesBoard[24].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(60, 65);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[25].getPosition().x -18, circlesBoard[25].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(61, 66);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[26].getPosition().x -18, circlesBoard[26].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}

	//-------------------

	edge = gph.getEdge(67, 71);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[29].getPosition().x -18, circlesBoard[29].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(68, 72);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[30].getPosition().x -18, circlesBoard[30].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(69, 73);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalRightRoad(circlesBoard[31].getPosition().x -18, circlesBoard[31].getPosition().y + 65, Player);
		GameWindow->draw(circleSegment);
	}



}

void Board::paintDiagonalLeftRoads()
{



	BoardEdge* edge;

	int Player = -1;


	edge = gph.getEdge(23, 20);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[0].getPosition().x + 45, circlesBoard[0].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}


	edge = gph.getEdge(24, 21);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[1].getPosition().x + 45, circlesBoard[1].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(25, 22);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[2].getPosition().x + 45, circlesBoard[2].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}



	//--------
	edge = gph.getEdge(31, 27);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[4].getPosition().x + 50, circlesBoard[4].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(32, 28);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[5].getPosition().x + 50, circlesBoard[5].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(33, 29);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[6].getPosition().x + 50, circlesBoard[6].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(34, 30);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[7].getPosition().x + 50, circlesBoard[7].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}


	//----------

	edge = gph.getEdge(41, 36);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[9].getPosition().x + 50, circlesBoard[9].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(42, 37);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[10].getPosition().x + 50, circlesBoard[10].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(43, 38);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[11].getPosition().x + 50, circlesBoard[11].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(44, 39);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[12].getPosition().x + 50, circlesBoard[12].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(45, 40);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[13].getPosition().x + 50, circlesBoard[13].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}


	//---------

	edge = gph.getEdge(53, 48);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[16].getPosition().x + 50, circlesBoard[16].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(54, 49);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[17].getPosition().x + 50, circlesBoard[17].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(55, 50);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[18].getPosition().x + 50, circlesBoard[18].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(56, 51);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[19].getPosition().x + 50, circlesBoard[19].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(57, 52);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[20].getPosition().x + 50, circlesBoard[20].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}


	//-----------


	edge = gph.getEdge(63, 59);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[23].getPosition().x + 50, circlesBoard[23].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}


	edge = gph.getEdge(64, 60);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[24].getPosition().x + 50, circlesBoard[24].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(65, 61);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[25].getPosition().x + 50, circlesBoard[25].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}

	edge = gph.getEdge(66, 62);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[26].getPosition().x + 50, circlesBoard[26].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}

	//-------------------

	edge = gph.getEdge(71, 68);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[29].getPosition().x + 50, circlesBoard[29].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(72, 69);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[30].getPosition().x + 50, circlesBoard[30].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}
	edge = gph.getEdge(73, 70);
	if (gph.hasRoad(edge)) {
		Player = edge->player;
		RectangleShape circleSegment = Const.renderDiagonalLeftRoad(circlesBoard[31].getPosition().x + 50, circlesBoard[31].getPosition().y + 50, Player);
		GameWindow->draw(circleSegment);
	}

}



void Board::paintRoadsOnBoard()
{
	paintVerticalRoads();
	paintDiagonalLeftRoads();
	paintDiagonalRightRoads();


}

void Board::selectTerrain()
{
	circlesBoard = c.drawCirclesBackground();

	for (int i = 0; i < 37; i++) {
		selectedCircle[i] = false;

	}

	for (int i = 0; i < 37; i++) {
		int dx = event.mouseMove.x - circlesBoard[i].getPosition().x;
		int dy = event.mouseMove.y - circlesBoard[i].getPosition().y;
		if (dx < 0) { dx = -dx; }
		if (dy < 0) { dy = -dy; }

		float d1 = dx * dx;
		float d2 = dy * dy;
		float d3 = d1 + d2;
		float d = sqrt(d3);

		if (d <= RADIUS) {

			selectedCircle[i] = true;
		}

		if (selectedCircle[i] == true) {
			cout << "circle selected: " << i<<endl;
		}
	}



	string a = playersName->getString();
	detectHexVertice(currentPlayer(playersName->getString()));


	if (vertFound == false) {
		detectHexHorizontalSegment(currentPlayer(playersName->getString()));
		detectHexDiagonalRightSegment(currentPlayer(playersName->getString()));
		detectHexDiagonalLeftSegment(currentPlayer(playersName->getString()));
	}



}

void Board::paintGameBoard()
{


}

void Board::detectHexHorizontalSegment(int currentPlayer) {

	for (int i = 0; i < circlesBoard.size(); i++) {
		if (selectedCircle[i] == true && selectedCircle[i + 1] == true) {


			CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 60, circlesBoard[i].getPosition().y, 10);
			GameWindow->draw(circleSegment);



			if (selectedCircle[4] == true && selectedCircle[5] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(23, 27, currentPlayer);
				}
			}
			if (selectedCircle[5] == true && selectedCircle[6] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(24, 28, currentPlayer);
				}
			}
			if (selectedCircle[6] == true && selectedCircle[7] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(25, 29, currentPlayer);
				}
			}
			if (selectedCircle[7] == true && selectedCircle[8] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(26, 30, currentPlayer);
				}
			}


			if (selectedCircle[8] == true && selectedCircle[9] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(25, 29, currentPlayer);
				}
			}
			if (selectedCircle[9] == true && selectedCircle[10] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(31, 36, currentPlayer);
				}
			}
			if (selectedCircle[10] == true && selectedCircle[11] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(32, 37, currentPlayer);
				}
			}
			if (selectedCircle[11] == true && selectedCircle[12] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(33, 38, currentPlayer);
				}
			}
			if (selectedCircle[12] == true && selectedCircle[13] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(34, 39, currentPlayer);
				}
			}
			if (selectedCircle[13] == true && selectedCircle[14] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(35, 40, currentPlayer);
				}
			}
			if (selectedCircle[15] == true && selectedCircle[16] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(41, 47, currentPlayer);
				}
			}
			if (selectedCircle[16] == true && selectedCircle[17] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(42, 48, currentPlayer);
				}
			}
			if (selectedCircle[17] == true && selectedCircle[18] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(43, 49, currentPlayer);
				}
			}
			if (selectedCircle[18] == true && selectedCircle[19] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(44, 50, currentPlayer);
				}
			}
			if (selectedCircle[19] == true && selectedCircle[20] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(45, 51, currentPlayer);

				}
			}
			if (selectedCircle[20] == true && selectedCircle[21] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(46, 52, currentPlayer);
				}
			}
			if (selectedCircle[22] == true && selectedCircle[23] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(53, 58, currentPlayer);
				}
			}
			if (selectedCircle[23] == true && selectedCircle[24] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(54, 59, currentPlayer);
				}
			}
			if (selectedCircle[24] == true && selectedCircle[25] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(55, 60, currentPlayer);
				}
			}
			if (selectedCircle[25] == true && selectedCircle[26] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(56, 61, currentPlayer);
				}
			}
			if (selectedCircle[26] == true && selectedCircle[27] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(57, 62, currentPlayer);
				}
			}
			if (selectedCircle[28] == true && selectedCircle[29] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(63, 67, currentPlayer);
				}
			}
			if (selectedCircle[29] == true && selectedCircle[30] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(64, 68, currentPlayer);
				}
			}
			if (selectedCircle[30] == true && selectedCircle[31] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(65, 69, currentPlayer);
				}
			}
			if (selectedCircle[31] == true && selectedCircle[32] == true) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					gph.buildRoadOnEdge(66, 70, currentPlayer);
				}
			}

			cout << "INTERSECCION ENTRE CIRCULOS" << i + 1 << " Y " << i + 2 << endl;
		}
	}
}


void Board::detectHexDiagonalLeftSegment(int currentPlayer) {
	for (int i = 0; i < circlesBoard.size(); i++) {
		if (i <= 3) {
			if (selectedCircle[i] == true && selectedCircle[i + 4] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 25, circlesBoard[i].getPosition().y + 43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
				if (selectedCircle[1] == true && selectedCircle[5] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(20, 24, currentPlayer);
					}
				}
				if (selectedCircle[2] == true && selectedCircle[6] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(21, 25, currentPlayer);
					}
				}
				if (selectedCircle[3] == true && selectedCircle[7] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(22, 26, currentPlayer);
					}
				}

			}
		}

		if (i > 3 && i <= 8) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
				if (selectedCircle[5] == true && selectedCircle[10] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(27, 32, currentPlayer);
					}
				}
				if (selectedCircle[6] == true && selectedCircle[11] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(28, 33, currentPlayer);
					}
				}
				if (selectedCircle[7] == true && selectedCircle[12] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(29, 34, currentPlayer);
					}
				}
				if (selectedCircle[8] == true && selectedCircle[13] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(30, 35, currentPlayer);
					}
				}
			}
		}

		if (i > 8 && i <= 14) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
				if (selectedCircle[10] == true && selectedCircle[16] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(36, 42, currentPlayer);
					}
				}
				if (selectedCircle[11] == true && selectedCircle[17] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(37, 43, currentPlayer);
					}
				}
				if (selectedCircle[12] == true && selectedCircle[18] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(38, 44, currentPlayer);
					}
				}
				if (selectedCircle[13] == true && selectedCircle[19] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(39, 45, currentPlayer);
					}
				}
				if (selectedCircle[14] == true && selectedCircle[20] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(40, 46, currentPlayer);
					}
				}
			}
		}

		if (i > 14 && i <= 21) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
				if (selectedCircle[16] == true && selectedCircle[22] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(47, 53, currentPlayer);
					}
				}
				if (selectedCircle[17] == true && selectedCircle[23] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(48, 54, currentPlayer);
					}
				}
				if (selectedCircle[18] == true && selectedCircle[24] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(49, 55, currentPlayer);
					}
				}
				if (selectedCircle[19] == true && selectedCircle[25] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(50, 56, currentPlayer);
					}
				}
				if (selectedCircle[20] == true && selectedCircle[26] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(51, 57, currentPlayer);
					}
				}
			}
		}

		if (i > 21 && i <= 27) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
				if (selectedCircle[23] == true && selectedCircle[28] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(58, 63, currentPlayer);
					}
				}
				if (selectedCircle[24] == true && selectedCircle[29] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(59, 64, currentPlayer);
					}
				}
				if (selectedCircle[25] == true && selectedCircle[30] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(60, 65, currentPlayer);
					}
				}
				if (selectedCircle[26] == true && selectedCircle[31] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(61, 66, currentPlayer);
					}
				}

			}
		}

		if (i > 27 && i <= 32) {
			if (selectedCircle[i] == true && selectedCircle[i + 4] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;

				if (selectedCircle[29] == true && selectedCircle[33] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(67, 71, currentPlayer);
					}
				}
				if (selectedCircle[30] == true && selectedCircle[34] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(68, 72, currentPlayer);
					}
				}
				if (selectedCircle[31] == true && selectedCircle[35] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(69, 73, currentPlayer);
					}
				}
			}
		}
		if (i > 32 && i <= 36) {
			if (selectedCircle[i] == true && selectedCircle[i + 4] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}
	}
}




void Board::detectHexDiagonalRightSegment(int currentPlayer) {

	for (int i = 0; i < circlesBoard.size(); i++) {
		if (i <= 3) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 25, circlesBoard[i].getPosition().y + 43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;

				if (selectedCircle[0] == true && selectedCircle[5] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(23, 20, currentPlayer);
					}
				}
				if (selectedCircle[1] == true && selectedCircle[6] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(24, 21, currentPlayer);
					}
				}
				if (selectedCircle[2] == true && selectedCircle[7] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(25, 22, currentPlayer);
					}
				}








				if (selectedCircle[29] == true && selectedCircle[34] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(71, 68, currentPlayer);
					}
				}

				if (selectedCircle[30] == true && selectedCircle[35] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(72, 69, currentPlayer);
					}
				}
				if (selectedCircle[31] == true && selectedCircle[36] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(73, 70, currentPlayer);
					}
				}







			}
		}

		if (i > 3 && i <= 8) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
				if (selectedCircle[4] == true && selectedCircle[10] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(31, 27, currentPlayer);
					}
				}
				if (selectedCircle[5] == true && selectedCircle[11] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(32, 28, currentPlayer);
					}
				}
				if (selectedCircle[6] == true && selectedCircle[12] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(33, 29, currentPlayer);
					}
				}
				if (selectedCircle[7] == true && selectedCircle[13] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(34, 30, currentPlayer);
					}
				}
			}
		}

		if (i > 8 && i <= 14) {
			if (selectedCircle[i] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
				if (selectedCircle[9] == true && selectedCircle[16] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(41, 36, currentPlayer);
					}
				}
				if (selectedCircle[10] == true && selectedCircle[17] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(42, 37, currentPlayer);
					}
				}
				if (selectedCircle[11] == true && selectedCircle[18] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(43, 38, currentPlayer);
					}
				}
				if (selectedCircle[12] == true && selectedCircle[19] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(44, 39, currentPlayer);
					}
				}

				if (selectedCircle[13] == true && selectedCircle[20] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(45, 40, currentPlayer);
					}
				}
			}
		}

		if (i > 14 && i <= 21) {
			if (selectedCircle[i] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
				if (selectedCircle[16] == true && selectedCircle[23] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(53, 48, currentPlayer);
					}
				}
				if (selectedCircle[17] == true && selectedCircle[24] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(54, 49, currentPlayer);
					}
				}
				if (selectedCircle[18] == true && selectedCircle[25] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(55, 50, currentPlayer);
					}
				}
				if (selectedCircle[19] == true && selectedCircle[26] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(56, 51, currentPlayer);
					}
				}
				if (selectedCircle[20] == true && selectedCircle[27] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(57, 52, currentPlayer);
					}
				}
			}
		}

		if (i > 21 && i <= 27) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
				if (selectedCircle[23] == true && selectedCircle[29] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(63, 59, currentPlayer);
					}
				}
				if (selectedCircle[24] == true && selectedCircle[30] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(64, 60, currentPlayer);
					}
				}
				if (selectedCircle[25] == true && selectedCircle[31] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(65, 61, currentPlayer);
					}
				}
				if (selectedCircle[26] == true && selectedCircle[32] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(66, 62, currentPlayer);
					}
				}

			}
		}

		if (i > 27 && i <= 32) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;

				if (selectedCircle[29] == true && selectedCircle[34] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(71, 68, currentPlayer);
					}
				}

				if (selectedCircle[30] == true && selectedCircle[35] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(72, 69, currentPlayer);
					}
				}
				if (selectedCircle[31] == true && selectedCircle[36] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildRoadOnEdge(73, 70, currentPlayer);
					}
				}






			}
		}
		if (i > 32 && i <= 36) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}
	}
}



void Board::detectHexVertice(int currentPlayer) {
	vertFound = false;

	for (int i = 0; i < circlesBoard.size(); i++) {
		//first circles line


		if (i <= 3) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 60, circlesBoard[i].getPosition().y + 30, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;
				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 1 << " Y " << i + 5 << endl;

				while (GameWindow->pollEvent(event)) {
					switch (event.type)
					{

					case Event::MouseButtonPressed:
						if (selectedCircle[0] == true && selectedCircle[1] == true && selectedCircle[5] == true) {
							if (Mouse::isButtonPressed(Mouse::Left)) {
								gph.buildSettlementOnVertex(20, currentPlayer);//Se contruye un poblado en el vertice 20
							}
						}
						if (selectedCircle[1] == true && selectedCircle[2] == true && selectedCircle[6] == true) {
							if (Mouse::isButtonPressed(Mouse::Left)) {
								gph.buildSettlementOnVertex(21, currentPlayer);//Se contruye un poblado en el vertice 20
							}
						}
						if (selectedCircle[2] == true && selectedCircle[3] == true && selectedCircle[7] == true) {
							if (Mouse::isButtonPressed(Mouse::Left)) {
								gph.buildSettlementOnVertex(22, currentPlayer);//Se contruye un poblado en el vertice 20
							}
						}
						break;
					}
				}




			}
		}


		if (i <= 3) {
			if (selectedCircle[i] == true && selectedCircle[i + 4] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 5, circlesBoard[i].getPosition().y + 56, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
				if (selectedCircle[0] == true && selectedCircle[4] == true && selectedCircle[5] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(23, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[1] == true && selectedCircle[5] == true && selectedCircle[6] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(24, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[2] == true && selectedCircle[6] == true && selectedCircle[7] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(25, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[3] == true && selectedCircle[7] == true && selectedCircle[8] == true) {
					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(26, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
			}
		}



		//second circles line


		if (i > 3 && i <= 8) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 60, circlesBoard[i].getPosition().y + 40, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;
				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 1 << " Y " << i + 6 << endl;

				if (selectedCircle[4] == true && selectedCircle[5] == true && selectedCircle[10] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(27, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[5] == true && selectedCircle[6] == true && selectedCircle[11] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(28, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[6] == true && selectedCircle[7] == true && selectedCircle[12] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(29, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[7] == true && selectedCircle[8] == true && selectedCircle[13] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(30, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}

			}
		}


		if (i > 3 && i <= 8) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x, circlesBoard[i].getPosition().y + 70, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 5 << " Y " << i + 6 << endl;

				if (selectedCircle[4] == true && selectedCircle[9] == true && selectedCircle[10] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(31, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[5] == true && selectedCircle[10] == true && selectedCircle[11] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(32, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[6] == true && selectedCircle[11] == true && selectedCircle[12] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(33, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[7] == true && selectedCircle[12] == true && selectedCircle[13] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(34, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[8] == true && selectedCircle[13] == true && selectedCircle[14] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(35, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
			}

		}

		//three circles line


		if (i > 8 && i <= 14) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 60, circlesBoard[i].getPosition().y + 35, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 1 << " Y " << i + 7 << endl;
				if (selectedCircle[9] == true && selectedCircle[10] == true && selectedCircle[16] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(36, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[10] == true && selectedCircle[11] == true && selectedCircle[17] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(37, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[11] == true && selectedCircle[12] == true && selectedCircle[18] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(38, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[12] == true && selectedCircle[13] == true && selectedCircle[19] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(39, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[13] == true && selectedCircle[14] == true && selectedCircle[20] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(40, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
			}
		}


		if (i > 8 && i <= 14) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 3, circlesBoard[i].getPosition().y + 65, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 6 << " Y " << i + 7 << endl;
				if (selectedCircle[9] == true && selectedCircle[15] == true && selectedCircle[16] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(41, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[10] == true && selectedCircle[16] == true && selectedCircle[17] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(42, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[11] == true && selectedCircle[17] == true && selectedCircle[18] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(43, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[12] == true && selectedCircle[18] == true && selectedCircle[19] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(44, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[13] == true && selectedCircle[19] == true && selectedCircle[20] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(45, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[14] == true && selectedCircle[20] == true && selectedCircle[21] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(46, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
			}
		}


		//four circles line


		if (i > 14 && i <= 21) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 65, circlesBoard[i].getPosition().y + 35, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 1 << " Y " << i + 7 << endl;
				if (selectedCircle[15] == true && selectedCircle[16] == true && selectedCircle[22] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(47, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[16] == true && selectedCircle[17] == true && selectedCircle[23] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(48, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[17] == true && selectedCircle[18] == true && selectedCircle[24] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(49, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[18] == true && selectedCircle[19] == true && selectedCircle[25] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(50, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[19] == true && selectedCircle[20] == true && selectedCircle[26] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(51, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[20] == true && selectedCircle[21] == true && selectedCircle[27] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(52, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
			}
		}


		if (i > 14 && i <= 21) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 5, circlesBoard[i].getPosition().y + 73, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 6 << " Y " << i + 7 << endl;
				if (selectedCircle[16] == true && selectedCircle[22] == true && selectedCircle[23] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(53, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[17] == true && selectedCircle[23] == true && selectedCircle[24] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(54, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[18] == true && selectedCircle[24] == true && selectedCircle[25] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(55, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[19] == true && selectedCircle[25] == true && selectedCircle[26] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(56, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[20] == true && selectedCircle[26] == true && selectedCircle[27] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(57, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}

			}
		}
		//five circles line


		if (i > 21 && i <= 27) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 60, circlesBoard[i].getPosition().y + 32, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 1 << " Y " << i + 6 << endl;
				if (selectedCircle[22] == true && selectedCircle[23] == true && selectedCircle[28] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(58, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[23] == true && selectedCircle[24] == true && selectedCircle[29] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(59, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[24] == true && selectedCircle[25] == true && selectedCircle[30] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(60, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[25] == true && selectedCircle[26] == true && selectedCircle[31] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(61, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[26] == true && selectedCircle[27] == true && selectedCircle[32] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(62, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
			}
		}


		if (i > 21 && i <= 27) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 2, circlesBoard[i].getPosition().y + 66, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 5 << " Y " << i + 6 << endl;
				if (selectedCircle[23] == true && selectedCircle[28] == true && selectedCircle[29] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(63, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[24] == true && selectedCircle[29] == true && selectedCircle[30] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(64, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[25] == true && selectedCircle[30] == true && selectedCircle[31] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(65, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[26] == true && selectedCircle[31] == true && selectedCircle[32] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(66, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
			}
		}

		//six circles line


		if (i > 27 && i <= 32) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 60, circlesBoard[i].getPosition().y + 32, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 1 << " Y " << i + 5 << endl;
				if (selectedCircle[28] == true && selectedCircle[29] == true && selectedCircle[33] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(67, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[29] == true && selectedCircle[30] == true && selectedCircle[34] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(68, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[30] == true && selectedCircle[31] == true && selectedCircle[35] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(69, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[31] == true && selectedCircle[32] == true && selectedCircle[36] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(70, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
			}
		}


		if (i > 27 && i <= 32) {
			if (selectedCircle[i] == true && selectedCircle[i + 4] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 2, circlesBoard[i].getPosition().y + 66, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
				if (selectedCircle[29] == true && selectedCircle[33] == true && selectedCircle[34] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(71, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[30] == true && selectedCircle[34] == true && selectedCircle[35] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(72, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
				if (selectedCircle[31] == true && selectedCircle[35] == true && selectedCircle[36] == true) {

					if (Mouse::isButtonPressed(Mouse::Left)) {
						gph.buildSettlementOnVertex(73, currentPlayer);//Se contruye un poblado en el vertice 20
					}
				}
			}
		}



		/*



		if (i > 3 && i <= 8) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 25, circlesBoard[i].getPosition().y + 43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 8 && i <= 14) {
			if (selectedCircle[i] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 25, circlesBoard[i].getPosition().y + 43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 14 && i <= 21) {
			if (selectedCircle[i] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 25, circlesBoard[i].getPosition().y + 43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 21 && i <= 27) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 25, circlesBoard[i].getPosition().y + 43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 27 && i <= 32) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 25, circlesBoard[i].getPosition().y + 43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}
		if (i > 32 && i <= 36) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 25, circlesBoard[i].getPosition().y + 43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}	*/
	}

}
