#include "ListPlayerCards.h"

ListPlayerCards::ListPlayerCards()
{
	first = NULL;
	nextNode = NULL;
}

NodeCard* ListPlayerCards::First()
{
	return first;
}

NodeCard* ListPlayerCards::NextNode()
{
	return nextNode;
}

void ListPlayerCards::addCard(int id, string name, string material)
{
	NodeCard* node = new NodeCard(Card(id, name, material));
	insertIntoList(node);
}

void ListPlayerCards::insertIntoList(NodeCard* newNode)
{
	if (first == NULL)
	{
		first = newNode;
		first->next = NULL;
	}
	else
	{
		newNode->next = first;
		first = newNode;
	}
}

void ListPlayerCards::showList()
{
	NodeCard* aux;
	aux = first;
	while (aux != NULL) {
		cout << aux->card.getNameCard() << " " << aux->card.getMaterial() << endl;
		if (aux->next != NULL) {
			aux = aux->next;
		}
		else {
			aux = NULL;
		}
	}
}
