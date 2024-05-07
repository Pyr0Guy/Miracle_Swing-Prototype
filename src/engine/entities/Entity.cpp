#include "Entity.h"

void Entity::InitVariables()
{
	this->texture = nullptr;
	this->sprite = nullptr;
	this->movementComponent = nullptr;
}

Entity::Entity()
{
	this->InitVariables();
}

Entity::~Entity()
{
	delete this->sprite;
}

void Entity::CreateSprite(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);
}

void Entity::CreateMovementComponent(const float maxVelocity)
{
	this->movementComponent = new MovementComponent(maxVelocity);
}

void Entity::setPosition(const float x, const float y)
{
	if (this->sprite)
		this->sprite->setPosition(x, y);
}

void Entity::Move(const float& dt, const float dir_x, const float dir_y)
{
	if (this->sprite && this->movementComponent)
	{
		this->movementComponent->Move(dir_x, dir_y); //This is Set Velocity
		this->sprite->move(this->movementComponent->getVelocity() * dt); //This is Use Velocity
	}
}

void Entity::Update(const float& dt)
{

}

void Entity::Render(sf::RenderTarget* target)
{
	if(this->sprite)
		target->draw(*this->sprite);
}

/* */