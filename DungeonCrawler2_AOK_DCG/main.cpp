#include "WorldMap.h"
#include "Collisions.h"
#include "Hero.h"
#include "UI.cpp"

int main() {
	bool isPlaying = true;

	WorldMap* worldMap = new WorldMap();
	Collisions::SetMap(worldMap->GetMap());

	Hero* player = new Hero(5, 5, 10, 5, 2);

	UI::setHero(player);
	UI::printUI();

	worldMap->GetMap()->InsertToGrid(player);

	worldMap->InitialDraw();
	while (isPlaying) {

	}
}