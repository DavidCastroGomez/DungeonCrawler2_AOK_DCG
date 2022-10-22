#include "Drop.h"

Drop::Drop()
{
}

Drop::Drop(int x, int y, int amou, DropType t)
{
	this->x = x;
	this->y = y;

	this->amount = amou;
	this->dropType = t;

	this->type = EntityType::DROP;

	switch (dropType)
	{
	case DropType::UNDEFINED:
		break;
	case DropType::POTION:
		this->symbol = 'P';
		break;
	case DropType::MONEY:
		this->symbol = 'M';
		break;
	default:
		break;
	}
}

Drop::~Drop()
{
}


int Drop::getAmount()
{
	return amount;
}

DropType Drop::getDropType()
{
	return dropType;
}

