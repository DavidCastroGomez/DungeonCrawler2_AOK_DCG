#include "Entity.h"

Entity::Entity()
{
	this->x = 0;
	this->y = 0;

	this->symbol = 'E';

	this->type = EntityType::UNDEFINED;
}

Entity::Entity(int x, int y, char symb, EntityType t)
{
	this->x = x;
	this->y = y;

	this->symbol = symb;

	this->type = t;
}

void Entity::Draw() {
	std::string s(1, symbol);
	DrawClass::Draw(x, y, s);
}

int Entity::getX()
{
	return x;
}

int Entity::getY()
{
	return y;
}

char Entity::getSymbol()
{
	return symbol;
}

void Entity::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

EntityType Entity::getType()
{
	return type;
}
