#include "Enemy.h"
Enemy::Enemy(int x, int y) : Character() {
	this->x = x;
	this->y = y;
	this->symbol = 'E';
	this->type = EntityType::ENEMY;

	this->moveTime = ENEMY_MOVE_TIME;
	this->health = ENEMY_HEALTH;

	this->damage = ENEMY_DAMAGE;

}

Enemy::~Enemy()
{
	actionThread->~thread();
	actionMutex->~mutex();
}

void Enemy::TryMove()
{
	
	int keyCode = rand() % 4;

	Entity* e = Collisions::CheckIfCanMove(x, y, keyCode);

	switch (e->getType()) {
	case EntityType::FLOOR:
		Move(keyCode);
		break;
	case EntityType::PORTAL:
	case EntityType::CHEST:
	case EntityType::WALL:
	case EntityType::DROP:
		break;
	case EntityType::HERO:
		Attack(e);
		break;
	}
}


void Enemy::Move(int direction) {
	int lastx = this->x;
	int lasty = this->y;

	switch (direction)
	{
	case 0:
		this->y -= 1;
		break;
	case 2:
		this->y += 1;
		break;
	case 3:
		this->x -= 1;
		break;
	case 1:
		this->x += 1;
		break;
	default:
		break;
	}

	Collisions::MoveCharacter(lastx, lasty);
}

void Enemy::Attack(Entity* e) {
	Character* character = (Character*)e;
	character->RecieveDamage(damage);
}

void Enemy::Die() {
	Collisions::RemoveEntity(x, y);
	Collisions::NewDrop(x, y);
	this->~Enemy();
}