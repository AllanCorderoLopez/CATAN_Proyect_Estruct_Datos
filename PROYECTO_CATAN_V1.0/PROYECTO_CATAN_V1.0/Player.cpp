#include "Player.h"
int idP = 0;

Player::Player()
{
	name = "";
	idPlayer = 0;
	age = 0;
	color = 0;

}

Player::Player(string n, int a, int c, ListPlayerCards listCard)
{
	name = n;
	idPlayer = idP++;
	age = a;
	color = c;
	listCards = listCard;
}

string Player::getName()
{
	return name;
}

int Player::getIdPlayer()
{
	return idPlayer;
}

int Player::getAge()
{
	return age;
}

int Player::getColor()
{
	return color;
}

ListPlayerCards Player::getListPlayerCards()
{
	return listCards;
}

void Player::setListCards(ListPlayerCards newList)
{
	listCards = newList;
}
