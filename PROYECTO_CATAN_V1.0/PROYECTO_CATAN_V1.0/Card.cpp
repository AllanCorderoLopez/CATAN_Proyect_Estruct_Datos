#include "Card.h"

Card::Card()
{
	idCard = 0;
	nameCard = "";
	material = "";

}

Card::Card(int cardId, string cardName, string cardMaterial)
{
	idCard = cardId;
	nameCard = cardName;
	material = cardMaterial;

}

int Card::getIdCard()
{
	return idCard;
}

string Card::getNameCard()
{
	return nameCard;
}

string Card::getMaterial()
{
	return material;
}
