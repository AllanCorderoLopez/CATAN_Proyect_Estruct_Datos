#include "Board.h"
#include "circle.h"
#include <sstream>
#include<stdlib.h>
#include<time.h>
#include <dos.h>
#include <iostream>
#include <vector>
using namespace sf;
using namespace std;
Sprite sprite;
Sprite sprite2;
Sprite sprite3;
Texture texture;
Texture texture2;
Texture texture3;
Event event;
const float RADIUS = 80;
vector<CircleShape> circlesBoard(100);
vector<bool> selectedCircle(100);
Circle c;
bool vertFound = false;
int num = 0;
vector<Terrain*> terrains(20);
vector<Sprite> spriteTerrains(20);
vector<Texture> textureTerrains(20);

vector<Sprite> spriteImagesCards(9);
vector<Texture> textureImagesCards(9);

vector<Sprite> spriteImagesCards2(8);
vector<Texture> textureImagesCards2(8);

Board::Board()
{

	GameWindow = new RenderWindow(VideoMode(1280, 720), "Game");

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

	numberPlayersCards = new Text();
	numberPlayersCards->setFont(*font);
	numberPlayersCards->setString(" 5");
	numberPlayersCards->setCharacterSize(19);

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
	string vecImages1[9] = { "RECURSOS/CARTAS NUEVAS/TABLA-COSTES.png","RECURSOS/CARTAS NUEVAS/CARTA-ARCILLA.png","RECURSOS/CARTAS NUEVAS/CARTA-LANA.png","RECURSOS/CARTAS NUEVAS/CARTA-MADERA.png","RECURSOS/CARTAS NUEVAS/CARTA-ROCA.png","RECURSOS/CARTAS NUEVAS/CARTA-TRIGO.png","RECURSOS/CARTAS NUEVAS/DESAROLLO-CABALLERO.png","RECURSOS/CARTAS NUEVAS/PROGRESO-CARRETERA.png","RECURSOS/CARTAS NUEVAS/PROGRESO-INVENTO.png" };
	string vecImages2[8] = { "RECURSOS/CARTAS NUEVAS/PROGRESO-MONOPOLIO.png","RECURSOS/CARTAS NUEVAS/PTS-AYUNTAMIENTO.png","RECURSOS/CARTAS NUEVAS/PTS-BIBLIOTECA.png","RECURSOS/CARTAS NUEVAS/PTS-IGLESIA.png","RECURSOS/CARTAS NUEVAS/PTS-MERCADO.png","RECURSOS/CARTAS NUEVAS/PTS-UNIVERSIDAD.png","RECURSOS/CARTAS NUEVAS/ESPECIAL-EJERCITO.png","RECURSOS/CARTAS NUEVAS/ESPECIAL-RUTA.png"};
	
	for (int i = 0; i < 9; i++) {
		string pathImageCard = vecImages1[i];
		texture2.loadFromFile(pathImageCard);
	    textureImagesCards[i] = texture2;
	}
	for (int i = 0; i < 8; i++) {
		string pathImageCard = vecImages2[i];
		texture3.loadFromFile(pathImageCard);
		textureImagesCards2[i] = texture3;
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

		for (int i = 0; i < 9; i++)
		{
			Sprite spriteImagesCards(textureImagesCards[i]);
			spriteImagesCards.setScale(85.f / spriteImagesCards.getTexture()->getSize().x, 90.f / spriteImagesCards.getTexture()->getSize().y);
			spriteImagesCards.setPosition(5, y);

	
		terrains2 = terrains;
			y = y + 80;

			GameWindow->draw(spriteImagesCards);
		}
		for (int i = 0; i < 8; i++)
		{
			Sprite spriteImagesCards(textureImagesCards2[i]);
			spriteImagesCards.setScale(85.f / spriteImagesCards.getTexture()->getSize().x, 90.f / spriteImagesCards.getTexture()->getSize().y);
			spriteImagesCards.setPosition(120, y2);

			y2 = y2 + 80;

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
	Node* current;//prueba
	current = list.First();

	playersName->setString(current->player.getName());
	//current->player.getListPlayerCards().showList();
	//GameWindow->display();
	while (GameWindow->isOpen()) {

		while (GameWindow->pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				GameWindow->close();

			else if (event.type == sf::Event::KeyPressed) {//esto hace que se pasen los nombres de jugadores
				if (Keyboard::isKeyPressed(Keyboard::Enter)) {
					playersName->setString(current->player.getName());
					current = current->next;
				}
			}
		}
		GameWindow->clear(sf::Color::Black);
		renderTerrains();
		

		paintFixedElements();
		GameWindow->draw(*playersName);
		createGameBoard();
		selectTerrain();
		//createGameBoard();
		
		GameWindow->display();

	}
	
}

void Board::paintFixedElements()//pinta los labels y recuadros
{
	float y = 95;
	float y2 = 95;
	RectangleShape currentPlayer({ 150,60 });
	currentPlayer.setPosition({ 10,10 });
	currentPlayer.setFillColor(Color::Blue);
	for (int i = 0; i < 9; i++) {

		x->setPosition({90,y});
		numberPlayersCards->setPosition({100,y});

		GameWindow->draw(*numberPlayersCards);
		GameWindow->draw(*x);
		y = y + 85;
	}
	for (int i = 0; i < 8; i++) {

		x->setPosition({ 200,y2 });
		numberPlayersCards->setPosition({210,y2});

		GameWindow->draw(*numberPlayersCards);
		GameWindow->draw(*x);
		y2 = y2 + 85;
	}
	GameWindow->draw(currentPlayer);
	GameWindow->draw(*titlePlayers);



}

void Board::paintCards()
{



}

void Board::createGameBoard()
{
	Circle c;
	c.drawCirclesBackground();
	drawCircles(c.drawCirclesBackground());

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




	detectHexVertice();


	if (vertFound == false) {
		detectHexHorizontalSegment();
		detectHexDiagonalRightSegment();
		detectHexDiagonalLeftSegment();
	}



}

void Board::paintGameBoard()
{


}

void Board::detectHexHorizontalSegment() {

	for (int i = 0; i < circlesBoard.size(); i++) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x+60, circlesBoard[i].getPosition().y, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION ENTRE CIRCULOS"<<i+1 << " Y " <<i+2 << endl;
			}
	}
}
void Board::detectHexDiagonalLeftSegment() {
	for (int i = 0; i < circlesBoard.size(); i++) {
		if (i <= 3) {
			if (selectedCircle[i] == true && selectedCircle[i + 4] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x -25, circlesBoard[i].getPosition().y + 43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 3 && i <= 8) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 8 && i <= 14) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 14 && i <= 21) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 21 && i <= 27) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 27 && i <= 32) {
			if (selectedCircle[i] == true && selectedCircle[i + 4] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
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


void Board::detectHexDiagonalRightSegment() {

	for (int i = 0; i < circlesBoard.size(); i++) {
		if (i <= 3) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 25, circlesBoard[i].getPosition().y+43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 3 && i<=8) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 8 && i <= 14) {
			if (selectedCircle[i] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 14 && i <= 21) {
			if (selectedCircle[i] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 21 && i <= 27) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 27 && i <= 32) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}
		if (i > 32 && i <= 36) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x +30, circlesBoard[i].getPosition().y + 50, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}
	}   
}




void Board::detectHexVertice() {
	vertFound = false;
	for (int i = 0; i < circlesBoard.size(); i++) {
		//first circles line


		if (i <= 3) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 60, circlesBoard[i].getPosition().y + 30, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;
				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}


		if (i <= 3) {
			if (selectedCircle[i] == true && selectedCircle[i + 4] == true && selectedCircle[i + 5] == true ) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x-5, circlesBoard[i].getPosition().y + 56, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}



		//second circles line


		if (i > 3 && i <= 8) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 60, circlesBoard[i].getPosition().y + 40, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}


		if (i > 3 && i <= 8) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x, circlesBoard[i].getPosition().y + 70, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}

		//three circles line


		if (i > 8 && i <= 14) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 60, circlesBoard[i].getPosition().y + 35, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}


		if (i > 8 && i <= 14) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x+3, circlesBoard[i].getPosition().y + 65, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}


		//four circles line


		if (i > 14 && i <= 21) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 65, circlesBoard[i].getPosition().y + 35, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}


		if (i > 14 && i <= 21) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x+5, circlesBoard[i].getPosition().y + 73, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}
		//five circles line


		if (i > 21 && i <= 27) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 60, circlesBoard[i].getPosition().y + 32, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}


		if (i > 21 && i <= 27) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x+2, circlesBoard[i].getPosition().y + 66, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}

		//six circles line


		if (i > 27 && i <= 32) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 60, circlesBoard[i].getPosition().y + 32, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}


		if (i > 27 && i <= 32 ) {
			if (selectedCircle[i] == true && selectedCircle[i + 4] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x+2, circlesBoard[i].getPosition().y + 66, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
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
