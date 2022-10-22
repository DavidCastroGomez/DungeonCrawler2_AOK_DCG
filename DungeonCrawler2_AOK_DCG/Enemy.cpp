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
}

void Enemy::Move(int direction) {

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