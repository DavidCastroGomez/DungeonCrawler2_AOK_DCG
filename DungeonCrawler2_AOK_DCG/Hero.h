#pragma once
#include "Character.h"
#include "InputManager.h"
#include "json/json.h"
//#include "Weapon.h"

class Hero : public Character
{
private:
	//Weapon weapon;
	int potions;
	int money;

	InputManager* inputs;
	std::thread* inputThread;
public:

	Hero();
	Hero(int x, int y, int health, int money, int potions);

	void TryMove() override;
	void Move(int direction) override;
	void Attack(Entity* e) override;
	void Die() override;

	void PickUp(Entity* e);

	int getHealth();
	int getMoney();
	int getPotions();

	void setHealth(int i);
	void setMoney(int i);
	void setPotions(int i);

	void OpenChest(Entity* e);

	static Hero* Parse(Json::Value jsonValue);
};


