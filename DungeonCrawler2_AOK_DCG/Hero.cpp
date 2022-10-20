#include "Hero.h"
Hero::Hero() : Character() {
	this->x = 5;
	this->y = 5;
	this->symbol = 'H';

	this->moveTime = 500;
	this->health = 20;

	this->money = 5;
	this->potions = 2;

	//this->weapon = Weapon();

	this->inputs = new InputManager();
	this->inputThread = new std::thread(&InputManager::StartListener, inputs);
	inputThread->detach();
}

void Hero::TryMove()
{
	int keyCode = inputs->LastInput();

	//Entity* e = Collisions::

	//switch (desiredPosition->getType()) {
	//case EntityType::CHARACTER:
	//case EntityType::WALL:
	//case EntityType::PORTAL:
	//	return true;
	//case EntityType::CHESTTYPE:
	//case EntityType::FLOORTYPE:
	//	/*case
	//		return true;
	//	*

	//		*/
	//case EntityType::UNDEFINEDTYPE:
	//	return false;
	//}
}

void Hero::Move() {

}

void Hero::Attack() {

}

void Hero::Die() {

}

void Hero::PickUp() {

}