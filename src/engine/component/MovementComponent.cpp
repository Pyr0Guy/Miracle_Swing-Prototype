#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity)
	:sprite(sprite), maxVelocity(maxVelocity)
{
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::Move(const float dir_x, const float dir_y, const float dt)
{
	this->velocity.x = dir_x * maxVelocity;
	this->velocity.y = dir_y * maxVelocity;

	this->sprite.move(this->velocity * dt);
}

void MovementComponent::Update(const float& dt)
{
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

/* */