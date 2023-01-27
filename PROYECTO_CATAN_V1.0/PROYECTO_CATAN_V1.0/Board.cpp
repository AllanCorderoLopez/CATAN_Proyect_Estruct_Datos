#include "Board.h"
#include "circle.h"
#include <sstream>
#include<stdlib.h>
#include<time.h>
#include <dos.h>
#include <iostream>
#include <vector>
#include <list>
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

vector<Sprite> spriteImagesCards(6);
vector<Texture> textureImagesCards(6);

vector<Sprite> spriteImagesCards2(6);
vector<Texture> textureImagesCards2(6);

vector<Sprite> spriteImagesCards3(5);
vector<Texture> textureImagesCards3(5);

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
	Node* current;//prueba
	current = list.First();

	playersName->setString(current->player.getName());
	//current->player.getListPlayerCards().showList();
	//GameWindow->display();
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
					playersName->setString(current->player.getName());
					numberPlayersCardsWool->setString(to_string(countCardsWool(current)[0]));
					numberPlayersCardsClay->setString(to_string(countCardsWool(current)[1]));
					numberPlayersCardsWood->setString(to_string(countCardsWool(current)[2]));
					numberPlayersCardsStone->setString(to_string(countCardsWool(current)[3]));
					numberPlayersCardsWheat->setString(to_string(countCardsWool(current)[4]));
					numberPlayersCardsMonopoly->setString(to_string(countCardsWool(current)[5]));
					numberPlayersCardsTownHall->setString(to_string(countCardsWool(current)[6]));
					numberPlayersCardsLibrary->setString(to_string(countCardsWool(current)[7]));
					numberPlayersCardsChurch->setString(to_string(countCardsWool(current)[8]));
					numberPlayersCardsMarket->setString(to_string(countCardsWool(current)[9]));
					numberPlayersCardsUniversity->setString(to_string(countCardsWool(current)[10]));
					numberPlayersCardsRoad->setString(to_string(countCardsWool(current)[11]));
					numberPlayersCardsInvention->setString(to_string(countCardsWool(current)[12]));
					numberPlayersCardsKnight->setString(to_string(countCardsWool(current)[13]));
					numberPlayersCardsArmy->setString(to_string(countCardsWool(current)[14]));
					numberPlayersCardsRoute->setString(to_string(countCardsWool(current)[15]));
					current = current->next;
				}
				break;
			case Event::MouseButtonPressed:
				Texture t;
				t.loadFromFile("RECURSOS/CARTAS GRANDES/TABLA-COSTES.png");
				Sprite ss(t);
				Sprite s(textureImagesCards[0]);
				s.setPosition(5, 70);
				s.setScale(100.f / s.getTexture()->getSize().x, 115.f / s.getTexture()->getSize().y);

				if (Mouse::isButtonPressed(Mouse::Left) && s.getGlobalBounds().contains((Vector2f)positionMouse)) {
					cout << "HOLA PERRAS----------------" << endl;
					RenderWindow* window = new RenderWindow(VideoMode(500, 500), "----");
					window->clear();
					window->draw(ss);
					window->display();
					
				}
				break;
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
	float y = 210;
	float y2 = 110;
	float y3 = 110;
	RectangleShape currentPlayer({ 150,60 });
	currentPlayer.setPosition({ 10,10 });
	currentPlayer.setFillColor(Color::Blue);
	
	for (int i = 0; i < 5; i++) {

		x->setPosition({90,y});
	    numberPlayersCardsWool->setPosition({ 100,210 });
		numberPlayersCardsClay->setPosition({ 100,310 });
		numberPlayersCardsWood->setPosition({ 100,410 });
		numberPlayersCardsStone->setPosition({ 100,510 });
		numberPlayersCardsWheat->setPosition({ 100,610 });
		
		/*numberPlayersCardsArmy->setPosition({100,y});
		numberPlayersCardsRoute->setPosition({ 100,y });
		numberPlayersCardsRoad->setPosition({ 100,y });
		numberPlayersCardsInvention->setPosition({ 100,y });
		numberPlayersCardsMonopoly->setPosition({ 100,y });
		numberPlayersCardsTownHall->setPosition({ 100,y });
		numberPlayersCardsLibrary->setPosition({ 100,y });
		numberPlayersCardsChurch->setPosition({ 100,y });
		numberPlayersCardsMarket->setPosition({ 100,y });
		numberPlayersCardsUniversity->setPosition({ 100,y });*/

		GameWindow->draw(*numberPlayersCardsClay);
		GameWindow->draw(*numberPlayersCardsWool);
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
	GameWindow->draw(*titlePlayers);



}

void Board::paintCards()
{



}

vector<int> Board::countCardsWool(Node* nodePlayer)
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
