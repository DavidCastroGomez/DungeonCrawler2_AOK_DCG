#include "Chest.h"
#include "Collisions.h"

Chest::Chest(int x, int y)
{
	this->x = x;
	this->y = y;

	this->type = EntityType::CHEST;
	this->symbol = 'C';
}

Chest::~Chest()
{
}

void Chest::OpenChest()
{
	Collisions::RemoveEntity(x, y);
	Collisions::NewDrop(x, y);	
}


