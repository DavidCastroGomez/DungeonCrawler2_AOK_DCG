#pragma once
#include "Entity.h"

class Chest : public Entity
{
public:
	Chest(int x, int y);

	void OpenChest();

	~Chest();
};

