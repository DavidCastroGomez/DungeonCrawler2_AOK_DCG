#include "WorldMap.h"
#include "Collisions.h"
#include "Hero.h"
#include "UI.h"
#include "LoadGame.h"
#include "SaveGame.h"

void ChangeMap() {

}

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


	while (player->getHealth() > 0) {
		if (Collisions::GetPortalEntered()) {
			Portal* p = Collisions::GetPortal();

			Entity* floor = worldMap->GetMap()->getSpawn().BuildFloor(player->getX(), player->getY());
			worldMap->GetMap()->InsertToGrid(floor);

			worldMap->ChangeMap(p);

			Collisions::SetMap(worldMap->GetMap());

			if (p->getXDir() == 1) {
				player->setPos(1, (MAP_ROWS - 1)/2);
			}
			else if (p->getXDir() == -1) {
				player->setPos(MAP_COLS - 2, (MAP_ROWS - 1) / 2);
			}
			else if (p->getYDir() == 1) {
				player->setPos((MAP_COLS - 1) / 2, MAP_ROWS - 2);
			}
			else if (p->getYDir() == -1) {
				player->setPos((MAP_COLS - 1) / 2, 1);
			}


			worldMap->GetMap()->InsertToGrid(player);

			Collisions::SetPortal(nullptr);
			Collisions::portalEntered = false;

			worldMap->InitialDraw();
		}
	}

	delete worldMap;

	savegame.EraseHero();

	system("cls");
	ConsoleControl::SetPosition(0, 0);
	std::cout << "YOU LOSE";

}