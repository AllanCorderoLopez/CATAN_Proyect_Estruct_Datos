#include "Card.h"

Card::Card()
{
	idCard = 0;
	nameCard = "";
	material = "";

}

Card::Card(int cardId)
{
	if (cardId == 1) {
		idCard = cardId;
		nameCard = "Oveja";
		material = "Lana";
	}
	if (cardId == 2) {
		idCard = cardId;
		nameCard = "Ladrillos";
		material = "Arcilla";
	}
	if (cardId == 3) {
		idCard = cardId;
		nameCard = "Troncos";
		material = "Madera";
	}
	if (cardId == 4) {
		idCard = cardId;
		nameCard = "Roca";
		material = "Mineral";
	}
	if (cardId == 5) {
		idCard = cardId;
		nameCard = "Trigo";
		material = "Cereal";
	}
	

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
