#pragma once
#include "Entity.h"
class Portal : public Entity
{
private:
	int xDir;
	int yDir;

public:
	Portal(int x, int y, int xDir, int yDir);

	int getXDir();
	int getYDir();
};

