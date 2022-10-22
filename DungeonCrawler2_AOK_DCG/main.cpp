#include "WorldMap.h"
#include "Collisions.h"
#include "Hero.h"
#include "UI.h"
#include "LoadGame.h"
#include "SaveGame.h"

int main() {
	bool isPlaying = true;

	WorldMap* worldMap = new WorldMap();
	Collisions::SetMap(worldMap->GetMap());

	LoadGame loadgame;


	Hero* player = loadgame.LoadHero();

	SaveGame savegame(player);

	UI::setHero(player);
	UI::printUI();

	worldMap->GetMap()->InsertToGrid(player);

	worldMap->InitialDraw();


	while (isPlaying) {

	}
}