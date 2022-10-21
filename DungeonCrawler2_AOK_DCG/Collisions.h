#pragma once
#include "Map.h"

static class Collisions
{
private:
	static Map* map;

public:
	
	static void SetMap(Map* m);
	static Entity* CheckIfCanMove(int x, int y, int direction);
	static void MoveCharacter(int lastX, int lastY, int x, int y);
};


