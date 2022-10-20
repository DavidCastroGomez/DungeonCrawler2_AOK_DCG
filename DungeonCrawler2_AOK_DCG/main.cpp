#include "WorldMap.h"

int main() {
	WorldMap* worldMap = new WorldMap();

	Map* map0 = new Map();
	Map* map1 = new Map();
	Map* map2 = new Map();
	Map* map3 = new Map();
	Map* map4 = new Map();
	Map* map5 = new Map();
	Map* map6 = new Map();
	Map* map7 = new Map();
	Map* map8 = new Map();

	worldMap->AddMap(map4, 1, 1);

	/*worldMap->AddMap(map0, 0, 0);
	worldMap.AddMap(map1, 0, 1);
	worldMap.AddMap(map2, 0, 2);
	worldMap.AddMap(map3, 1, 0);
	worldMap.AddMap(map4, 1, 1);
	worldMap.AddMap(map5, 1, 2);
	worldMap.AddMap(map6, 2, 0);
	worldMap.AddMap(map7, 2, 1);
	worldMap.AddMap(map8, 2, 2);*/


	worldMap->InitialDraw();
}