#include "Entity.h"

void Entity::InitVariables()
{
	this->texture = nullptr;
	this->movementComponent = nullptr;
	this->hitboxComponent = nullptr;
}

Entity::Entity()
{
	this->InitVariables();
}

Entity::~Entity()
{
	//delete this->sprite;
	delete this->hitboxComponent;
	delete this->movementComponent;
}

void Entity::CreateSprite(sf::Texture* texture)
{
	this->texture = texture;
	//this->sprite = new sf::Sprite(*this->texture);
	this->sprite.setTexture(*this->texture);
}

void Entity::CreateHitboxComponent(sf::Sprite& sprite, const float offset_x, const float offset_y, const float width, const float height)
{
	this->hitboxComponent = new HitboxComponent(sprite, offset_x, offset_y, width, height);
}

void Entity::CreateMovementComponent(const float maxVelocity)
{
	this->movementComponent = new MovementComponent(maxVelocity);
}

void Entity::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Entity::Move(const float& dt, const float dir_x, const float dir_y)
{
	if (this->movementComponent)
	{
		this->movementComponent->Move(dir_x, dir_y); //This is Set Velocity
		this->sprite.move(this->movementComponent->getVelocity() * dt); //This is Use Velocity
	}
}

void Entity::Update(const float& dt)
{

}

void Entity::Render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

	if (this->hitboxComponent)
		this->hitboxComponent->Render(target);
}

/* */