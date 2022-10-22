#pragma once
#include "Character.h"
class Enemy : public Character
{

public:
	Enemy(int x, int y);
	~Enemy();
	
	void TryMove() override;
	void Move(int direction) override;
	void Attack(Entity* e) override;
	void Die() override;

};

