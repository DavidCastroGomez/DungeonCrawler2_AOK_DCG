#include "WorldMap.h"

WorldMap::WorldMap()
{
	maps.resize(WORLDMAP_COLS);
	for (int i = 0; i < WORLDMAP_COLS; i++) {
		maps[i].resize(WORLDMAP_ROWS);
	}

	currentMapX = 1;
	currentMapY = 1;	

	Map* map0 = new Map(1);
	Map* map1 = new Map(1);
	Map* map2 = new Map(1);
	Map* map3 = new Map(1);
	Map* map4 = new Map(5);
	Map* map5 = new Map(1);
	Map* map6 = new Map(1);
	Map* map7 = new Map(1);
	Map* map8 = new Map(1);

	this->AddMap(map4, 1, 1);

	this->AddMap(map0, 0, 0);
	this->AddMap(map1, 0, 1);
	this->AddMap(map2, 0, 2);
	this->AddMap(map3, 1, 0);
	this->AddMap(map4, 1, 1);
	this->AddMap(map5, 1, 2);
	this->AddMap(map6, 2, 0);
	this->AddMap(map7, 2, 1);
	this->AddMap(map8, 2, 2);
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
		e = m->getSpawn().BuildPortal(0, (MAP_ROWS - 1) / 2, -1, 0);
		m->InsertToGrid(e);
	}
	
	//DERECHA
	if (currentMapX != WORLDMAP_COLS - 1) {
		e = m->getSpawn().BuildPortal((MAP_COLS - 1) , (MAP_ROWS - 1) / 2, 1, 0);
		m->InsertToGrid(e);
	}

	//ARRIBA
	if (currentMapY != 0) {
		e = m->getSpawn().BuildPortal((MAP_COLS - 1) / 2, 0, 0, 1);
		m->InsertToGrid(e);
	}

	//ABAJO
	if (currentMapY != WORLDMAP_ROWS - 1) {
		e = m->getSpawn().BuildPortal((MAP_COLS - 1) / 2, MAP_ROWS - 1, 0 , -1);
		m->InsertToGrid(e);
	}
	
}

void WorldMap::ChangeMap(Portal* p)
{
	currentMapX += p->getXDir();
	currentMapY += p->getYDir();

}

void WorldMap::UpdateMap()
{
}

Map* WorldMap::GetMap()
{
	return maps[currentMapX][currentMapY];
}
