#include "Node.h"
#include <iostream>
using namespace std;

const unsigned int x = 10;
const unsigned int y = 10;

Node::Node()
{
	next = NULL;
	previous = NULL;
}

Node::Node(Player p)
{
	next = NULL;
	previous = NULL;
	player = p;
}

Node::~Node()
{
	next = NULL;
	previous = NULL;

}

Node* Node::Next()
{
	return next;
}

Node* Node::Previous()
{
	return previous;
}

Player& Node::PlayerName() {
	return player;
}


ListCurrentPlayers::ListCurrentPlayers()
{
	first = NULL;
	last = NULL;
	nextNode = NULL;
}

Node* ListCurrentPlayers::First()
{
	return first;
}

Node* ListCurrentPlayers::Last()
{
	return last;
}

Node* ListCurrentPlayers::NextNode()
{
	return nextNode;
}

void ListCurrentPlayers::insertList(Node* newNode)
{
	if (first == NULL)
	{
		newNode->next = newNode; newNode->previous = newNode; first = newNode; last = newNode;
	}
	else
	{
		newNode->next = first; newNode->previous = last;
		last->next = newNode;
		last = newNode;
		first->previous = newNode;
	}

}

void ListCurrentPlayers::CreatePictures()
{


}

void ListCurrentPlayers::AddPlayerName(string namePlayer, int agePlayer, int color, ListPlayerCards list)
{
	Node* node = new Node(Player(namePlayer, agePlayer, color, list));
	insertList(node);
}



void ListCurrentPlayers::showList()
{
	Node* aux;
	aux = first;
	while (aux != NULL) {
		cout << aux->player.getName() << " " << aux->player.getAge() << endl;
		if (aux != last) {
			aux = aux->next;
		}
		else {
			aux = NULL;
		}
	}

}


