#include "Portal.h"

Portal::Portal(int x, int y, int xDir, int yDir) : Entity(x, y, 'O', EntityType::PORTAL)
{
	this->xDir = xDir;
	this->yDir = yDir;
}

int Portal::getXDir()
{
	return xDir;
}

int Portal::getYDir()
{
	return yDir;
}
