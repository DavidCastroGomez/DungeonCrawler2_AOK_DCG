#include "Spawner.h"
#include "Enemy.h"

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
	return new Entity();
}
