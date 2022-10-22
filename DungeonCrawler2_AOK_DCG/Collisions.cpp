#include "Collisions.h"

Map* Collisions::map;
Portal* Collisions::portal;
bool Collisions::portalEntered = false;
std::mutex* Collisions::moveMutex = new std::mutex();

void Collisions::SetMap(Map* m)
{
	Collisions::map = m;
}

Entity* Collisions::CheckIfCanMove(int x, int y, int direction)
{
	
	Entity* desiredPosition = map->getEntity(x, y);

	moveMutex->lock();
	switch (direction)
	{
	case 0:
	case KB_UP:
		desiredPosition = map->getEntity(x, y - 1);
		break;
	case 1:
	case KB_RIGHT:
		desiredPosition = map->getEntity(x + 1, y);
		break;
	case 2:
	case KB_DOWN:
		desiredPosition = map->getEntity(x, y + 1);
		break;
	case 3:
	case KB_LEFT:
		desiredPosition = map->getEntity(x - 1, y);
		break;
	default:
		break;
	}
	moveMutex->unlock();
	return desiredPosition;
}

void Collisions::MoveCharacter(int lastX, int lastY)
{
	moveMutex->lock();
	Entity* e = map->getEntity(lastX, lastY);
	Entity* floor = map->spawner.BuildFloor(lastX, lastY);
	map->InsertToGrid(floor);
	floor->Draw();
	map->InsertToGrid(e);
	e->Draw();
	moveMutex->unlock();
}

void Collisions::RemoveEntity(int x, int y)
{
	Entity* floor = map->spawner.BuildFloor(x, y);
	map->InsertToGrid(floor);
	floor->Draw();	
}

void Collisions::NewDrop(int x, int y)
{
	Entity* drop = map->spawner.SpawnDrop(x, y);
	map->InsertToGrid(drop);
	drop->Draw();
}

void Collisions::SetPortal(Portal* p)
{
	portalEntered = true;
	portal = p;

}

Portal* Collisions::GetPortal()
{
	return portal;
}

bool Collisions::GetPortalEntered()
{
	return portalEntered;
}


