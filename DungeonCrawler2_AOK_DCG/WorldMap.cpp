#include "WorldMap.h"

WorldMap::WorldMap()
{
	maps.resize(WORLDMAP_COLS);
	for (int i = 0; i < WORLDMAP_COLS; i++) {
		maps[i].resize(WORLDMAP_ROWS);
	}

	currentMapX = 1;
	currentMapY = 1;
}

void WorldMap::AddMap(Map* m, int x, int y)
{
	maps[x][y] = m;
}

void WorldMap::InitialDraw()
{
	Map* map = maps[currentMapX][currentMapY];
	CreatePortals(map);

	std::vector<std::vector<Entity*>> grid = map->getGrid();
	
	for (std::vector<Entity*> v : grid) {
		for (Entity* e : v) {

			e->Draw();
		}
	}
}

void WorldMap::CreatePortals(Map* m)
{
	Entity* e;

	//IZQUIERDA
	if (currentMapX != 0) {
		e = m->getSpawn().BuildPortal((MAP_COLS - 1) / 2, 0, -1, 0);
		m->InsertToGrid(e);
	}

	//DERECHA
	if (currentMapX != WORLDMAP_COLS - 1) {
		e = m->getSpawn().BuildPortal((MAP_COLS - 1) / 2, MAP_ROWS - 1, 1, 0);
		m->InsertToGrid(e);
	}

	//ARRIBA
	if (currentMapY != 0) {
		e = m->getSpawn().BuildPortal(0 / 2, MAP_ROWS - 1, 0, 1);
		m->InsertToGrid(e);
	}

	//ABAJO
	if (currentMapY != WORLDMAP_ROWS - 1) {
		e = m->getSpawn().BuildPortal((MAP_COLS - 1) / 2, MAP_ROWS - 1, 0 , -1);
		m->InsertToGrid(e);
	}
}

void WorldMap::ChangeMap(Entity*)
{
}

void WorldMap::UpdateMap()
{
}
