#pragma once
#include "Card.h"
#include <iostream>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
using namespace std;

class NodeCard
{
public:
	NodeCard* next;
	Card card;

public:
	NodeCard();
	NodeCard(Card);
	NodeCard* Next();
	Card& Cards();
};

