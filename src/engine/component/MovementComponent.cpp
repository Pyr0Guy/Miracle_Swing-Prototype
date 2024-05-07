#include "MovementComponent.h"

MovementComponent::MovementComponent(float maxVelocity)
	:maxVelocity(maxVelocity)
{
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::Move(const float dir_x, const float dir_y)
{
	this->velocity.x = dir_x * maxVelocity;
	this->velocity.y = dir_y * maxVelocity;
}

void MovementComponent::Update(const float& dt)
{
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

/* */