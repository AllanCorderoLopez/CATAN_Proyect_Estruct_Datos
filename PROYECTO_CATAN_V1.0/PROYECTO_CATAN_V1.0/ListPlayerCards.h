#pragma once
#include "NodeCard.h"
#include <iostream>
#include "Card.h"

using namespace std;

class ListPlayerCards
{
private:
	NodeCard* first;
	NodeCard* nextNode;

public:
	ListPlayerCards();
	NodeCard* First();
	NodeCard* NextNode();
	void addCard(int);
	void deleteCard(int);
	void insertIntoList(NodeCard*);
	void showList();
};

