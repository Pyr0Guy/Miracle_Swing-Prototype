#include "Enemy.h"

Enemy::Enemy(sf::Texture& texture, float x, float y)
	: x(x), y(y)
{
	this->sprite.setTexture(texture);

	this->setPosition(x, y);
	this->CreateMovementComponent(100.f);
	this->SetOrigin(this->sprite.getTexture()->getSize().x / 2, this->sprite.getTexture()->getSize().y / 2);

	this->counter = 0;
	this->amplitude = 30;
	this->speed = 1;
	this->radians = 0.f;

	this->spawnTimer = 0.5f;
}

Enemy::~Enemy()
{
}

void Enemy::Update(const float& dt)
{
	/*
	this->movementComponent->Move(
		std::cos(time(NULL)),
		std::sin(time(NULL) / 2),
		dt
	);
	*/

	this->radians = (this->counter * (3.14 / 100));
	this->counter++;
	//if (this->counter >= 360)
	//	this->counter = 0;

	this->sprite.setPosition(x + cos(this->radians * 0.1) * (this->amplitude * 7), y + sin(this->radians * this->speed) * this->amplitude);

	this->spawnTimer -= 1.f * dt;
}
