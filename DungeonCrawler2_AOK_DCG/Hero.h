#pragma once
#include "Character.h"
#include "InputManager.h"
//#include "Weapon.h"

#include <thread>

class Hero : public Character
{
private:
	//Weapon weapon;
	int potions;
	int money;
	
	InputManager* inputs;
	std::thread* inputThread;
public:
	Hero(int x, int y, int health, int money, int potions);

	void TryMove() override;
	void Move(int direction) override;
	void Attack() override;
	void Die() override;

	void PickUp() override;
};

