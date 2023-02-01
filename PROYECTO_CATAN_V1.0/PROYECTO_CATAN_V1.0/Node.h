#pragma once
#include <iostream>
#include "Player.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
using namespace std;

class Node {

public://atributos
	Node* next;
	Node* previous;
	Player player;

public://metodos
	Node();
	Node(Player);
	~Node();

	Node* Next();
	Node* Previous();
	Player& PlayerName();

	/*void setSigNodo(Node* sig);
	Node* getSigNodo();
	void setAntNodo(Node* sig);
	Node* getAntNodo();*/


};

class ListCurrentPlayers {
private:
	Node* first;
	Node* last;
	Node* nextNode;

public:
	ListCurrentPlayers();
	Node* First();
	Node* Last();
	Node* NextNode();
	void CreatePictures();
	void AddPlayerName(string, int, int, ListPlayerCards);
	void insertList(Node*);
	void showList();


};


