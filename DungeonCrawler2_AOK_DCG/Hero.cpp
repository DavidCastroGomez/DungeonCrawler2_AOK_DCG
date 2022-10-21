#include "Hero.h"
Hero::Hero(int x, int y, int health, int money, int potions) : Character() {
	this->x = x;
	this->y = y;
	this->symbol = 'H';

	this->moveTime = 500;
	this->health = health;

	this->money = money;
	this->potions = potions;

	//this->weapon = Weapon();

	this->inputs = new InputManager();
	this->inputThread = new std::thread(&InputManager::StartListener, inputs);
	inputThread->detach();
}

void Hero::TryMove()
{
	int keyCode = inputs->LastInput();

	//TODO CHANGE THIS
	if (keyCode == KB_UP || keyCode == KB_DOWN || keyCode == KB_LEFT || keyCode == KB_RIGHT) {
		Entity* e = Collisions::CheckIfCanMove(x, y, keyCode);	//X AND Y ARENT THE DESTINATION

		switch (e->getType()) {
		case EntityType::WALL:
			break;
		case EntityType::DROP:
			PickUp();
		case EntityType::FLOOR:
			Move(keyCode);
			break;
		case EntityType::ENEMY:
		case EntityType::CHEST:
			Attack();
			break;	
		case EntityType::PORTAL:
			//TODO portal call to change map
			break;
		}
	}

}

void Hero::Move(int direction) {
	int lastx = x;
	int lasty = y;

	switch (direction)
	{
	case KB_UP:
		this->y -= 1;
		break;
	case KB_DOWN:
		this->y += 1;
		break;
	case KB_LEFT:
		this->x -= 1;
		break;
	case KB_RIGHT:
		this->x += 1;
		break;
	default:
		break;
	}

	Collisions::MoveCharacter(lastx, lasty, x, y);
}

void Hero::Attack() {

}

void Hero::Die() {

}

void Hero::PickUp() {

}