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
	
	InputManager* inputs;
	std::thread* InputThread;
public:
	Hero();

	void Move() override;
	void Attack() override;
	void Die() override;

	void PickUp() override;
};

