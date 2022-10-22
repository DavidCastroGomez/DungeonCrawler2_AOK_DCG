#pragma once
#include "Map.h"

static class Collisions
{
private:
	static Map* map;
	static std::mutex* moveMutex;
	
	static Portal* portal;

public:
	static bool portalEntered;

	static void SetMap(Map* m);
	static Entity* CheckIfCanMove(int x, int y, int direction);
	static void MoveCharacter(int lastX, int lastY);
	static void RemoveEntity(int x, int y);
	static void NewDrop(int x, int y);
	static void SetPortal(Portal* p);
	static Portal* GetPortal();
	static bool GetPortalEntered();
};


