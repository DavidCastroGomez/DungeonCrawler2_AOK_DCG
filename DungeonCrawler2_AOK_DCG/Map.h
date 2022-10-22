#pragma once

#include <vector>
#include <thread>
#include <mutex>

#include "Entity.h"
#include "Spawner.h"


class Map
{
private:

	bool portalEntered;

	std::vector<std::vector<Entity*>> grid;

	//why a pointer
	std::thread* spawnerThread;
	std::mutex* spawnerMutex;

public:
	

	Spawner spawner;

	Map(int numOfEnemiesAndChests);

	void SpawnRandom();
	void InsertToGrid(Entity* e);

	Entity* getEntity(int, int);

	std::vector<std::vector<Entity*>> getGrid();

	Spawner getSpawn();

};



