#include "Game.h"

Game::Game()
{

	fontTitle = new Font();//titulo
	fontTitle->loadFromFile("COUGAR.ttf");
	fontOptions = new Font();//titulo
	fontOptions->loadFromFile("Chickenic.ttf");

	listCurrentPlayers;

	titleGame = new Text();
	titleGame->setFont(*fontTitle);
	titleGame->setString(" CATAN ");
	titleGame->setPosition({ 225,10 });
	titleGame->setOrigin(titleGame->getGlobalBounds().width / 2, 5);
	titleGame->setCharacterSize(75);

	labelNewGame = new Text();//labelNewGame
	labelNewGame->setFont(*fontOptions);
	labelNewGame->setString("New Game ");
	labelNewGame->setPosition({ 235,185 });
	labelNewGame->setCharacterSize(25);
	labelNewGame->setFillColor(sf::Color::Black);

	labelLoadGame = new Text();//labelLoadGame
	labelLoadGame->setFont(*fontOptions);
	labelLoadGame->setString("Load Game ");
	labelLoadGame->setPosition({ 235,265 });
	labelLoadGame->setCharacterSize(25);
	labelLoadGame->setFillColor(sf::Color::Black);

	labelSelectPlayers = new Text();
	labelSelectPlayers->setFont(*fontTitle);
	labelSelectPlayers->setString("- Seleccione la Cantidad de Jugadores - ");
	labelSelectPlayers->setPosition({ 155,35 });
	labelSelectPlayers->setOrigin(titleGame->getGlobalBounds().width / 2, 5);
	labelSelectPlayers->setCharacterSize(28);

	labelTwoPlayers = new Text();//
	labelTwoPlayers->setFont(*fontOptions);
	labelTwoPlayers->setString("2 Players ");
	labelTwoPlayers->setPosition({ 235,165 });
	labelTwoPlayers->setCharacterSize(25);
	labelTwoPlayers->setFillColor(sf::Color::Black);

	labelThreePlayers = new Text();//
	labelThreePlayers->setFont(*fontOptions);
	labelThreePlayers->setString("3 Players ");
	labelThreePlayers->setPosition({ 235,245 });
	labelThreePlayers->setCharacterSize(25);
	labelThreePlayers->setFillColor(sf::Color::Black);

	labelFourPlayers = new Text();//
	labelFourPlayers->setFont(*fontOptions);
	labelFourPlayers->setString("4 Players ");
	labelFourPlayers->setPosition({ 235,325 });
	labelFourPlayers->setCharacterSize(25);
	labelFourPlayers->setFillColor(sf::Color::Black);

	labelBegginerLevel = new Text();//
	labelBegginerLevel->setFont(*fontOptions);
	labelBegginerLevel->setString("Begginer Level");
	labelBegginerLevel->setPosition({ 212,185 });
	labelBegginerLevel->setCharacterSize(25);
	labelBegginerLevel->setFillColor(sf::Color::Black);

	labelAdvancedLevel = new Text();//
	labelAdvancedLevel->setFont(*fontOptions);
	labelAdvancedLevel->setString("Advanced Level");
	labelAdvancedLevel->setPosition({ 212,265 });
	labelAdvancedLevel->setCharacterSize(25);
	labelAdvancedLevel->setFillColor(sf::Color::Black);

	firstMenu = NULL;
	secondMenu = NULL;
	loadGameWindow = NULL;
	levelsWindow = NULL;

	for (int i = 0; i < 2; i++) {
		optionsfirstMenu[i] = new RectangleShape({ 210,60 });
		optionsfirstMenu[i]->setFillColor(Color::White);
	}
	optionsfirstMenu[0]->setPosition({ 195,170 });
	optionsfirstMenu[1]->setPosition({ 195,250 });

	for (int i = 0; i < 3; i++) {
		optionsSecondMenu[i] = new RectangleShape({ 190,60 });
		optionsSecondMenu[i]->setFillColor(Color::White);
	}
	optionsSecondMenu[0]->setPosition({ 195,150 });
	optionsSecondMenu[1]->setPosition({ 195,230 });
	optionsSecondMenu[2]->setPosition({ 195,310 });

	for (int i = 0; i < 2; i++) {
		optionsOfLeves[i] = new RectangleShape({ 210,60 });
		optionsOfLeves[i]->setFillColor(Color::White);
	}
	optionsOfLeves[0]->setPosition({ 195,170 });
	optionsOfLeves[1]->setPosition({ 195,250 });
}

void Game::startGame()
{
	gameType();
}

void Game::gameType()
{
	firstMenu = new RenderWindow(VideoMode(600, 500), "CATAN");
	while (firstMenu->isOpen()) {
		Event event;
		positionMouse = Mouse::getPosition(*firstMenu);

		while (firstMenu->pollEvent(event)) {

			switch (event.type)
			{
			case Event::Closed:
				firstMenu->close();
				break;

			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Enter)) {
					

				}
				break;

			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Left) && optionsfirstMenu[0]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					firstMenu->close();
					chooseLevel();

				}
				else if (Mouse::isButtonPressed(Mouse::Left) && optionsfirstMenu[1]->getGlobalBounds().contains((Vector2f)positionMouse)) {

				}
				break;
			}
		}
		firstMenu->clear(sf::Color::Black);

		for (int i = 0; i < 2; i++) {
			firstMenu->draw(*optionsfirstMenu[i]);
		}

		firstMenu->draw(*titleGame);
		firstMenu->draw(*labelNewGame);
		firstMenu->draw(*labelLoadGame);

		firstMenu->display();

	}
}

void Game::numberOfPlayers()
{
	int numberOfPlayers = 0;
	secondMenu = new RenderWindow(VideoMode(600, 500), "CATAN");

	while (secondMenu->isOpen()) {
		Event event;
		positionMouse = Mouse::getPosition(*secondMenu);
		while (secondMenu->pollEvent(event)) {
			switch (event.type)
			{
			case Event::Closed:
				secondMenu->close();
				break;

			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Left) && optionsSecondMenu[0]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					numberOfPlayers = 2;
					secondMenu->close();
					Register(numberOfPlayers);
				}
				else if (Mouse::isButtonPressed(Mouse::Left) && optionsSecondMenu[1]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					numberOfPlayers = 3;
					secondMenu->close();
					Register(numberOfPlayers);
				}
				else if (Mouse::isButtonPressed(Mouse::Left) && optionsSecondMenu[2]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					numberOfPlayers = 4;
					secondMenu->close();
					Register(numberOfPlayers);
				}
				break;
			}
		}
		secondMenu->clear(sf::Color::Black);
		for (int i = 0; i < 3; i++) {
			secondMenu->draw(*optionsSecondMenu[i]);
		}
		secondMenu->draw(*labelSelectPlayers);
		secondMenu->draw(*labelTwoPlayers);
		secondMenu->draw(*labelThreePlayers);
		secondMenu->draw(*labelFourPlayers);
		secondMenu->display();

	}

}

void Game::Register(int numberOfPlayers)
{
	string player1Name = "";
	string player2Name = "";
	string player3Name = "";
	string player4Name = "";

	int player1Age = 0;
	int player2Age = 0;
	int player3Age = 0;
	int player4Age = 0;

	int player1Color = 0;
	int player2Color = 0;
	int player3Color = 0;
	int player4Color = 0;

	cout << "\t\t-- Digite los datos de cada jugador  --" << endl << endl;

	if (numberOfPlayers == 2) {
		cout << "Colores para cada jugador: 1.Azul, 2.Amarillo" << endl << endl;
	}
	else if (numberOfPlayers == 3) {
		cout << "Colores para cada jugador: 1.Azul, 2.Amarillo, 3.Blanco" << endl << endl;
	}
	else {
		cout << "Colores para cada jugador: 1.Azul, 2.Amarillo, 3.Blanco, 4.Rojo" << endl << endl;
	}

	cout << "\tJugador 1: " << endl << endl;
	cout << " Nombre: ";
	cin >> player1Name;
	cout << " Edad: ";
	cin >> player1Age;
	cout << " Color: ";
	if (numberOfPlayers == 4) {
		do {
			cin >> player1Color;
		} while ((player1Color != 1) && (player1Color != 2) && (player1Color != 3) && (player1Color != 4));
	} else if (numberOfPlayers == 3) {
		do {
			cin >> player1Color;
		} while ((player1Color != 1) && (player1Color != 2) && (player1Color != 3));
	}
	else {
		do {
			cin >> player1Color;
		} while ((player1Color != 1) && (player1Color != 2));
	}
	ListPlayerCards listP1;
	listP1.addCard(2);
	listP1.addCard(2);
	listP1.addCard(2);
	listP1.addCard(2);
	listCurrentPlayers.AddPlayerName(player1Name, player1Age, player1Color, listP1);
	cout << endl;

	cout << "\tJugador 2: " << endl << endl;
	cout << " Nombre: ";
	do {
		cin >> player2Name;
	} while (player2Name._Equal(player1Name));
	cout << " Edad: ";
	cin >> player2Age;
	cout << " Color: ";
	if (numberOfPlayers == 4) {
		do {
			cin >> player2Color;
		} while ((player2Color != 1) && (player2Color != 2) && (player2Color != 3) && (player2Color != 4) && (player2Color != player1Color) || (player2Color == player1Color));
	}
	else if (numberOfPlayers == 3) {
		do {
			cin >> player2Color;
		} while ((player2Color != 1) && (player2Color != 2) && (player2Color != 3) && (player2Color != player1Color) || (player2Color == player1Color));
	}
	else {
		do {
			cin >> player2Color;
		} while ((player2Color != 1) && (player2Color != 2) || (player2Color == player1Color));
	}
	ListPlayerCards listP2;
	listP2.addCard(1);
	listP2.addCard(1);
	listP2.addCard(1);
	listCurrentPlayers.AddPlayerName(player2Name, player2Age, player2Color, listP2);
	cout << endl;

	if (numberOfPlayers == 3) {
		cout << "Jugador 3: " << endl << endl;
		cout << " Nombre: ";
		do {
			cin >> player3Name;
		} while (player3Name._Equal(player1Name) && player3Name._Equal(player2Name));
		cout << " Edad: ";
		cin >> player3Age;
		cout << " Color: ";
		do {
			cin >> player3Color;
		} while ((player3Color != 1) && (player3Color != 2) && (player3Color != 3) || (player3Color == player2Color) || (player3Color == player1Color));
		ListPlayerCards listP3;
		listP3.addCard(3);
		listP3.addCard(3);
		listP3.addCard(3);
		listCurrentPlayers.AddPlayerName(player3Name, player3Age, player3Color, listP3);
	}
	else if (numberOfPlayers == 4) {
		cout << "\tJugador 3: " << endl << endl;
		cout << " Nombre: ";
		do {
			cin >> player3Name;
		} while (player3Name._Equal(player1Name) && player3Name._Equal(player2Name));
		cout << " Edad: ";
		cin >> player3Age;
		cout << " Color: ";
		do {
			cin >> player3Color;
		} while ((player3Color != 1) && (player3Color != 2) && (player3Color != 3) && (player3Color != 4) || (player3Color == player2Color) || (player3Color == player1Color));
		ListPlayerCards listP3;
		listP3.addCard(3);
		listP3.addCard(3);
		listP3.addCard(3);
		listCurrentPlayers.AddPlayerName(player3Name, player3Age, player3Color, listP3);
		cout << endl;

		cout << "\tJugador 4: " << endl << endl;
		cout << " Nombre: ";
		do {
			cin >> player4Name;
		} while (player4Name._Equal(player1Name) && player4Name._Equal(player2Name) && player4Name._Equal(player3Name));
		cout << " Edad: ";
		cin >> player4Age;
		cout << " Color: ";
		do {
			cin >> player4Color;
		} while ((player4Color != 1) && (player4Color != 2) && (player4Color != 3) && (player4Color != 4) || (player4Color == player3Color) || (player4Color == player2Color) || (player4Color == player1Color));
		ListPlayerCards listP4;
		listP4.addCard(4);
		listP4.addCard(4);
		listP4.addCard(4);
		listCurrentPlayers.AddPlayerName(player4Name, player4Age, player4Color, listP4);
		cout << endl;


	}
	listCurrentPlayers.showList();
	listP1.showList();
	listP2.showList();
	cout << "   INICIANDO JUEGO..." << endl;
	system("pause");
	system("cls");

	Board boardGame;
	boardGame.renderMenu(listCurrentPlayers);
}

void Game::loadGame()
{


}

void Game::chooseLevel()
{
	levelsWindow = new RenderWindow(VideoMode(600, 500), "CATAN");
	while (levelsWindow->isOpen()) {
		Event event;
		positionMouse = Mouse::getPosition(*levelsWindow);

		while (levelsWindow->pollEvent(event)) {

			switch (event.type)
			{
			case Event::Closed:
				levelsWindow->close();
				break;

			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Enter)) {


				}
				break;

			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Left) && optionsOfLeves[0]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					

				}
				else if (Mouse::isButtonPressed(Mouse::Left) && optionsOfLeves[1]->getGlobalBounds().contains((Vector2f)positionMouse)) {
					levelsWindow->close();
					numberOfPlayers();
				}
				break;
			}
		}
		levelsWindow->clear(sf::Color::Black);

		for (int i = 0; i < 2; i++) {
			levelsWindow->draw(*optionsOfLeves[i]);
		}

		levelsWindow->draw(*titleGame);
		levelsWindow->draw(*labelBegginerLevel);
		levelsWindow->draw(*labelAdvancedLevel);

		levelsWindow->display();

	}
}

ListCurrentPlayers Game::getList()
{
	return listCurrentPlayers;
}
