#pragma once

#include "Entity.h"
#include "ConsoleControl.h"
#include "Collisions.h"

#include <thread>
#include <mutex>

class Character :
	public Entity
{
protected:
	int health;
	int moveTime;
	bool isTired;
	int damage;

	int movementSeed;

	std::thread* actionThread;
	std::mutex* actionMutex;
public:
	Character();

	void Act();
	void RecieveDamage(int damage);

	virtual void TryMove() = 0;
	virtual void Move(int direction) = 0;	//Move uses collisions
	virtual void Attack(Entity* e) = 0;	//Attack uses collisions
	virtual void Die() = 0;



};



