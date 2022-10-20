#pragma once
#include "Map.h"

static class Collisions
{
private:
	

public:
	static Map map;
	static void SetMap(Map m);
	static Entity* CheckIfCanMove(int x, int y, int direction);
};

