#include "Map.h"

Map::Map(int numOfEnemiesAndChests)
{
	spawnerMutex = new std::mutex();

	for (int i = 0; i < MAP_COLS; i++) {

		std::vector<Entity*> dimension;

		for (int j = 0; j < MAP_ROWS; j++) {

			if (i == 0 || i == MAP_COLS - 1 || j == 0 || j == MAP_ROWS - 1)
			{
				Entity* e = new Entity(i, j, '#', EntityType::WALL);
				dimension.push_back(e);
			}
			else
			{
				Entity* e = new Entity(i, j, ' ', EntityType::FLOOR);
				dimension.push_back(e);
			}
		}
		grid.push_back(dimension);
	}

	srand(time(NULL));
	for (int i = 0; i < numOfEnemiesAndChests; i++) {
		SpawnRandom();
	}
}

void Map::SpawnRandom()
{
	Entity* e = new Entity();
	int newSpawn = rand() % 4;

	int x;
	int y;
	do {
		x = (rand() % (MAP_COLS - 2)) + 1;
		y = (rand() % (MAP_ROWS - 2)) + 1;
	} while (grid[x][y]->getType() != EntityType::FLOOR);

	switch (newSpawn)
	{
	case 0:
	case 1:
	case 2:
		e = spawner.SpawnEnemy(x, y);
		break;
	case 3:
		e = spawner.SpawnChest(x, y);
		break;
	default:
		break;
	}
	grid[e->getX()][e->getY()] = e;
}

void Map::InsertToGrid(Entity* e)
{
	spawnerMutex->lock();
	grid[e->getX()][e->getY()] = e;
	spawnerMutex->unlock();
}

Entity* Map::getEntity(int x, int y)
{
	return grid[x][y];
}

std::vector<std::vector<Entity*>> Map::getGrid()
{
	return grid;
}

Spawner Map::getSpawn()
{
	return spawner;
}
