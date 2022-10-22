#pragma once
#include "Entity.h"
#include "Portal.h"

//#include "Chest.h"
//#include "Enemy.h"

class Drop;

class Spawner
{
public:
	Entity* BuildWall(int x, int y);
	Entity* BuildFloor(int x, int y);
	Entity* BuildPortal(int x, int y, int xDir, int yDir);

	//void SpawnHero(int x, int y);

	Entity* SpawnEnemy(int x, int y);
	Entity* SpawnChest(int x, int y);
	Entity* SpawnDrop(int x, int y);
};

