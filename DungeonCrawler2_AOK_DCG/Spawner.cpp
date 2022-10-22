#include "Spawner.h"
#include "Enemy.h"
#include "Drop.h"
#include "Chest.h"

Entity* Spawner::BuildWall(int x, int y)
{
	return new Entity(x, y, ' ', EntityType::WALL);
}

Entity* Spawner::BuildFloor(int x, int y)
{
	return new Entity(x, y, ' ', EntityType::FLOOR);
}

Entity* Spawner::BuildPortal(int x, int y, int xDir, int yDir)
{
	return new Portal(x, y, xDir, yDir);
}

Entity* Spawner::SpawnEnemy(int x, int y)
{
	return new Enemy(x, y);
}

Entity* Spawner::SpawnChest(int x, int y)
{
	return new Chest(x, y);
}

Entity* Spawner::SpawnDrop(int x, int y)
{
	int newDropType = rand() % 3;
	switch (newDropType)
	{
	case 0:
	case 1:
		return new Drop(x, y, (rand() % 5) + 1, DropType::MONEY);
	case 2:
		return new Drop(x, y, (rand() % 2) + 1, DropType::POTION);
	default:
		break;
	}
}
