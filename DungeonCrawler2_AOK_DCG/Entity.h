#pragma once

#include <iostream>
#include "ConsoleControl.h"
#include "Constants.h"
#include "DrawClass.h"

enum class EntityType {
	UNDEFINED,
	WALL,
	FLOOR,
	ENEMY,
	CHEST,
	HERO,
	DROP,
	PORTAL
};

class Entity
{
protected:
	int x, y;
	char symbol;
	EntityType type;

public:
	Entity();
	Entity(int x, int y, char symb, EntityType t);

	void Draw();
	void setPos(int x, int y);

	int getX();
	int getY();
	char getSymbol();
	EntityType getType();
};



