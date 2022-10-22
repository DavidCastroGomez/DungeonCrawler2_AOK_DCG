#include "Character.h"

Character::Character() : Entity()
{
	this->health = 0;
	this->damage = 0;

	this->moveTime = 0;
	this->isTired = false;

	this->actionThread = new std::thread(&Character::Act, this);
	this->actionMutex = new std::mutex();

	actionThread->detach();
}

void Character::Act()
{
	while (true) {
		actionMutex->lock();
		isTired = true;
		actionMutex->unlock();

		ConsoleControl::Wait(moveTime);

		actionMutex->lock();
		isTired = false;
		actionMutex->unlock();

		if (!isTired) {
			TryMove();
		}
	}
}

void Character::RecieveDamage(int damage)
{
	actionMutex->lock();
	health -= damage;
	actionMutex->unlock();

	if (health <= 0) {
		Die();
	}

}



//hero has varibale to be tired
//if is tired no move
//if not tired can recieve move