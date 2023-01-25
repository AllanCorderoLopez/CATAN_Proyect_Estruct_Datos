#include "NodeCard.h"
#include <iostream>
#include "Card.h"

using namespace std;

NodeCard::NodeCard() {
    next = NULL;
}

NodeCard::NodeCard(Card c)
{
    card = c;
}

NodeCard* NodeCard::Next()
{
    return next;
}

Card& NodeCard::Cards()
{
    return card;
}
