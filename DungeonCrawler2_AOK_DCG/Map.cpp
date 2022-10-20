#include "Map.h"

Map::Map()
{
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


}

void Map::SpawnRandom()
{
}

void Map::InsertToGrid(Entity* e)
{
	grid[e->getX()][e->getY()] = e;
}

void Map::UpdateGrid(Entity* e)
{
	/*Entity* temp;

	temp->x = grid at e->getX();
	temp->y = grid at e->getY();

	grid[e->getX()][e->getY()] = e;*/

	grid[e->getX()][e->getY()] = e;
	//TODO: make it so that after an element moves something is blank is painted behind it.
	e->Draw();
}

void Map::UpdateGrid(int x, int y)
{
	Entity* e = grid[x][y];

	//TODO: make it so that after an element moves something is blank is painted behind it.
	e->Draw();
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
