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

	Map(int numOfEnemies);

	void SpawnRandom();
	void InsertToGrid(Entity* e);

	void UpdateGrid(Entity* e);
	void UpdateGrid(int x, int y);

	Entity* getEntity(int, int);

	std::vector<std::vector<Entity*>> getGrid();

	Spawner getSpawn();

};



