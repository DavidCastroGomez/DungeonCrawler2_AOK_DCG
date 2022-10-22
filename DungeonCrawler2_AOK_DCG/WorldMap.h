#pragma once
#include "Map.h"
#include <vector>

class WorldMap
{
private:
	std::vector<std::vector<Map*>> maps;
	int currentMapX;
	int currentMapY;

public:
	WorldMap();
	void AddMap(Map* m, int x, int y);
	void InitialDraw();
	void CreatePortals(Map* m);

	void ChangeMap(Portal* p);
	void UpdateMap();
	Map* GetMap();

};

