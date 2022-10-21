#include "WorldMap.h"
#include "Collisions.h"
#include "Hero.h"

int main() {
	bool isPlaying = true;

	WorldMap* worldMap = new WorldMap();
	Collisions::SetMap(worldMap->GetMap());

	Hero* player = new Hero(5, 5, 10, 5 , 2);

	worldMap->GetMap()->InsertToGrid(player);

	worldMap->InitialDraw();
	while (isPlaying) {

	}
}