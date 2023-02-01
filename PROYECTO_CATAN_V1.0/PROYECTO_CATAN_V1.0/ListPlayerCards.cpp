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

void ListPlayerCards::addCard(int id)
{
	NodeCard* node = new NodeCard(Card(id));
	insertIntoList(node);
}

void ListPlayerCards::deleteCard(int data)
{
	NodeCard* node;
	NodeCard* nodeAux = first;
	node = first;
	while (node != NULL) {
		if (nodeAux->card.getIdCard() == data) {
			if (nodeAux == first) {
				first = nodeAux->next;
				delete nodeAux;
			}
			else {
				node->next = nodeAux->next;
				delete nodeAux;
			}
			node = NULL;
			
		}
		else {
			node = nodeAux;
			nodeAux = nodeAux->next;

		}
	}
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
