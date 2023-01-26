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
Texture texture;
Event event;
const float RADIUS = 75;
vector<CircleShape> circlesBoard(100);
vector<bool> selectedCircle(100);
Circle c;
bool vertFound = false;
int num = 0;
vector<Terrain*> terrains(20);
vector<Sprite> spriteTerrains(20);
vector<Texture> textureTerrains(20);



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



		for (int i = 0; i < 19; i++)
		{
			Sprite sprite(textureTerrains[i]);
			sprite.setScale(0.3f, 0.3f);
			if (i < 3)
				sprite.setPosition(400 + (i * 130), 50);
			if (i >= 3 && i < 7)
				sprite.setPosition(-55 + (i * 130), 165);
			if (i >= 7 && i < 12)
				sprite.setPosition(-640 + (i * 130), 280);
			if (i >= 12 && i < 16)
				sprite.setPosition(-1225 + (i * 130), 395);
			if (i >= 16)
				sprite.setPosition(-1680 + (i * 130), 510);

			GameWindow->draw(sprite);
		}


	
		terrains2 = terrains;


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
		GameWindow->clear(sf::Color::White);
		renderTerrains();
		

		paintFixedElements();
		GameWindow->draw(*playersName);
		createGameBoard();
		selectTerrain();
		GameWindow->display();

	}

}

void Board::paintFixedElements()//pinta los labels y recuadros
{
	float y = 90;
	float y2 = 90;
	Text* txt = new Text();
	txt->setString("Jugadores:");

	RectangleShape currentPlayer({ 250,75 });
	currentPlayer.setPosition({ 10,10 });
	currentPlayer.setFillColor(Color::Blue);

	GameWindow->draw(currentPlayer);
	GameWindow->draw(*txt); 
	GameWindow->draw(*titlePlayers);

	for (int i = 0; i < 9; i++) {
		RectangleShape currentCards({ 40,60 });
		currentCards.setPosition({ 10,y });
		currentCards.setFillColor(Color::Green);
		GameWindow->draw(currentCards);
		y = y + 69;
	}

	for (int i = 0; i < 8; i++) {
		RectangleShape currentCards({ 40,60 });
		currentCards.setPosition({ 130,y2 });
		currentCards.setFillColor(Color::Red);
		GameWindow->draw(currentCards);
		y2 = y2 + 69;
	}


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

	for (int i = 0; i < circlesBoard.size(); i++) {
		selectedCircle[i] = false;

	}

	for (int i = 0; i < circlesBoard.size(); i++) {
		int dx = event.mouseMove.x - circlesBoard[i].getPosition().x;
		int dy = event.mouseMove.y - circlesBoard[i].getPosition().y;
		if (dx < 0) { dx = -dx; }
		if (dy < 0) { dy = -dy; }

		float d1 = dx * dx;
		float d2 = dy * dy;
		float d3 = d1 + d2;
		float d = sqrt(d3);

		if (d <= RADIUS) {
			circlesBoard[i].setOutlineColor(Color(255, 181, 0, 0));
			circlesBoard[i].setFillColor(Color(255, 181, 0, 0));
			selectedCircle[i] = true;
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
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x+50, circlesBoard[i].getPosition().y-3, 10);
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
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 25, circlesBoard[i].getPosition().y + 43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 8 && i <= 14) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 25, circlesBoard[i].getPosition().y + 43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 14 && i <= 21) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 25, circlesBoard[i].getPosition().y + 43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 21 && i <= 27) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 25, circlesBoard[i].getPosition().y + 43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}

		if (i > 27 && i <= 32) {
			if (selectedCircle[i] == true && selectedCircle[i + 4] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 25, circlesBoard[i].getPosition().y + 43, 10);
				GameWindow->draw(circleSegment);

				cout << "INTERSECCION DIAGONAL ENTRE CIRCULOS" << i + 1 << " Y " << i + 6 << endl;
			}
		}
		if (i > 32 && i <= 36) {
			if (selectedCircle[i] == true && selectedCircle[i + 4] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x - 25, circlesBoard[i].getPosition().y + 43, 10);
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
		}
	}   
}




void Board::detectHexVertice() {
	vertFound = false;
	for (int i = 0; i < circlesBoard.size(); i++) {
		//first circles line


		if (i <= 3) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 50, circlesBoard[i].getPosition().y + 30, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;
				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}


		if (i <= 3) {
			if (selectedCircle[i] == true && selectedCircle[i + 4] == true && selectedCircle[i + 5] == true ) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x , circlesBoard[i].getPosition().y + 56, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}



		//second circles line


		if (i > 3 && i <= 8) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 50, circlesBoard[i].getPosition().y + 30, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}


		if (i > 3 && i <= 8) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x, circlesBoard[i].getPosition().y + 56, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}

		//three circles line


		if (i > 8 && i <= 14) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 50, circlesBoard[i].getPosition().y + 30, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}


		if (i > 8 && i <= 14) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x, circlesBoard[i].getPosition().y + 56, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}


		//four circles line


		if (i > 14 && i <= 21) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 50, circlesBoard[i].getPosition().y + 30, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}


		if (i > 14 && i <= 21) {
			if (selectedCircle[i] == true && selectedCircle[i + 6] == true && selectedCircle[i + 7] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x, circlesBoard[i].getPosition().y + 56, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}
		//five circles line


		if (i > 21 && i <= 27) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 50, circlesBoard[i].getPosition().y + 30, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}


		if (i > 21 && i <= 27) {
			if (selectedCircle[i] == true && selectedCircle[i + 5] == true && selectedCircle[i + 6] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x, circlesBoard[i].getPosition().y + 56, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}

		//six circles line


		if (i > 27 && i <= 32) {
			if (selectedCircle[i] == true && selectedCircle[i + 1] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x + 50, circlesBoard[i].getPosition().y + 30, 10);
				GameWindow->draw(circleSegment);
				vertFound = true;

				cout << "VERTICE ENCONTRADO" << i << " Y " << i + 4 << " Y " << i + 5 << endl;
			}
		}


		if (i > 27 && i <= 32) {
			if (selectedCircle[i] == true && selectedCircle[i + 4] == true && selectedCircle[i + 5] == true) {
				CircleShape circleSegment = c.createCircle(circlesBoard[i].getPosition().x, circlesBoard[i].getPosition().y + 56, 10);
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
