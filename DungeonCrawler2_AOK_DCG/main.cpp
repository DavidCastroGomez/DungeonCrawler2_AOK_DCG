#include "WorldMap.h"
#include "Collisions.h"
#include "Hero.h"
#include "UI.h"
#include "LoadGame.h"
#include "SaveGame.h"

int main() {
	bool isPlaying = false;

	WorldMap* worldMap = new WorldMap();
	Collisions::SetMap(worldMap->GetMap());

	LoadGame loadgame;
	SaveGame savegame;

	Hero* player = loadgame.LoadHero();

	UI::setHero(player);
	UI::printUI();

	worldMap->GetMap()->InsertToGrid(player);

	worldMap->InitialDraw();


	while (isPlaying) {

	}
}