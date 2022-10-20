#pragma once
#include "Character.h"
class Enemy : public Character
{
private:
	int damage;

public:
	Enemy();
	
	void Move() override;
	void Attack() override;
	void Die() override;
};

