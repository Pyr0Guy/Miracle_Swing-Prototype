#include "Entity.h"

void Entity::InitVariables()
{
	this->movementComponent = nullptr;
	this->hitboxComponent = nullptr;
	this->attackComponent = nullptr;
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
	delete this->attackComponent;
}

void Entity::SetTexture(sf::Texture& texture)
{
	//this->sprite = new sf::Sprite(*this->texture);
	this->sprite.setTexture(texture);
}

void Entity::CreateHitboxComponent(sf::Sprite& sprite, const float offset_x, const float offset_y, const float width, const float height)
{
	this->hitboxComponent = new HitboxComponent(sprite, offset_x, offset_y, width, height);
}

void Entity::CreateMovementComponent(const float maxVelocity)
{
	this->movementComponent = new MovementComponent(sprite,maxVelocity);
}

void Entity::SetOrigin(const float x, const float y)
{
	this->sprite.setOrigin(x, y);
}

void Entity::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Entity::Move(const float& dt, const float dir_x, const float dir_y)
{
	if (this->movementComponent)
	{
		this->movementComponent->Move(dir_x, dir_y, dt); //This is Set Velocity
	}
}

void Entity::Update(const float& dt)
{
	if (this->movementComponent)
		this->movementComponent->Update(dt);
}

void Entity::Render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

	if (this->hitboxComponent)
		this->hitboxComponent->Render(target);
	
	if (this->attackComponent)
		this->attackComponent->Render(target);
}

/* */