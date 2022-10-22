#pragma once
#include "Entity.h"
enum class DropType {
	UNDEFINED, POTION, MONEY
};

class Drop : public Entity
{
private:
	int amount;
	DropType dropType;

public:
	Drop();

	Drop(int x, int y, int amou, DropType t);
	~Drop();

	int getAmount();

	DropType getDropType();
};