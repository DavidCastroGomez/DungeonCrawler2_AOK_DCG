#include "Collisions.h"


void Collisions::SetMap(Map m)
{
	map = m;
}

Entity* Collisions::CheckIfCanMove(int x, int y, int direction)
{
	Entity* desiredPosition = map.getEntity(x, y);

	switch (direction)
	{
	case 0:
	case KB_UP:
		desiredPosition = map.getEntity(x, y - 1);
		break;
	case 1:
	case KB_RIGHT:
		desiredPosition = map.getEntity(x + 1, y);
		break;
	case 2:
	case KB_DOWN:
		desiredPosition = map.getEntity(x, y + 1);
		break;
	case 3:
	case KB_LEFT:
		desiredPosition = map.getEntity(x - 1, y);
		break;
	default:
		break;
	}

	return desiredPosition;
}
