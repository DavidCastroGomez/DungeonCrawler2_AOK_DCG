#pragma once

#include "Entity.h"
#include "ConsoleControl.h"

#include <thread>
#include <chrono>
#include <mutex>

class Character :
	public Entity
{
protected:
	int health;
	int moveTime;
	bool isTired;

	std::thread* actionThread;
	std::mutex* actionMutex;
public:
	Character();

	void Act();
	void RecieveDamage(int damage);

	virtual void Move() = 0;	//Move uses collisions
	virtual void Attack() = 0;	//Attack uses collisions
	virtual void Die() = 0;

	virtual void PickUp() = 0;	//PickUp uses collisions

};



