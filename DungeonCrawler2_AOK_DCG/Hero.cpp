#include "Hero.h"
#include "UI.h"
#include "Chest.cpp"
#include "Drop.h"
Hero::Hero(int x, int y, int health, int money, int potions) : Character() {
	this->x = x;
	this->y = y;
	this->symbol = 'H';
	this->type = EntityType::HERO;

	this->moveTime = HERO_MOVE_TIME;
	this->health = health;

	this->money = money;
	this->potions = potions;

	this->damage = HERO_DAMAGE;


	this->inputs = new InputManager();
	this->inputThread = new std::thread(&InputManager::StartListener, inputs);
	inputThread->detach();
}

void Hero::TryMove()
{
	int keyCode = inputs->LastInput();

	if (keyCode == KB_UP || keyCode == KB_DOWN || keyCode == KB_LEFT || keyCode == KB_RIGHT) {

		Entity* e = Collisions::CheckIfCanMove(x, y, keyCode);

		switch (e->getType()) {
		case EntityType::WALL:
			break;
		case EntityType::DROP:
			PickUp(e);
		case EntityType::FLOOR:
			Move(keyCode);
			break;
		case EntityType::ENEMY:
			Attack(e);
			break;
		case EntityType::CHEST:
			OpenChest(e);
			break;
		case EntityType::PORTAL:
			//TODO portal call to change map
			break;
		}
	}

}

void Hero::Move(int direction) {
	int lastx = this->x;
	int lasty = this->y;

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

	Collisions::MoveCharacter(lastx, lasty);
}

void Hero::Attack(Entity* e) {
	Character* character = (Character*)e;
	character->RecieveDamage(damage);
}

void Hero::Die() {

}

void Hero::PickUp(Entity* e) {
	Drop* drop = (Drop*)e;

	Collisions::RemoveEntity(e->getX(), e->getY());

	switch (drop->getDropType())
	{
	case DropType::MONEY:
		money += drop->getAmount();
		break;
	case DropType::POTION:
		potions += drop->getAmount();
		break;
	default:
		break;
	}


	UI::printUI();
}

int Hero::getHealth()
{
	return health;
}

int Hero::getMoney()
{
	return money;
}

int Hero::getPotions()
{
	return potions;
}

void Hero::OpenChest(Entity* e)
{
	Chest* c = (Chest*)e;
	c->OpenChest();
}
