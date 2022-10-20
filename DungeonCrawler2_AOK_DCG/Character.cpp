#include "Character.h"

Character::Character() : Entity()
{
	this->health = 0;

	this->moveTime = 0;
	this->isTired = false;

	this->actionThread = new std::thread(&Character::Act, this);
	this->actionMutex = new std::mutex();

	actionThread->detach();
}

void Character::Act()
{

	actionMutex->lock();
	//cansar
	actionMutex->unlock();
	ConsoleControl::Wait(moveTime);
	actionMutex->lock();
	//descansar
	actionMutex->unlock();
}

void Character::RecieveDamage(int damage)
{
	health -= damage;
	if (health <= 0) {
		Die();
	}
}



//hero has varibale to be tired
//if is tired no move
//if not tired can recieve move