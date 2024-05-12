#include "Bullet.h"

Bullet::Bullet(sf::Texture& texture, const float x, const float y, float dirX, float dirY, float moveSpeed)
	: dirX(dirX),
	dirY(dirY),
	moveSpeed(moveSpeed)
{
	this->sprite.setTexture(texture);
	this->setPosition(x, y);

	this->CreateMovementComponent(moveSpeed);
	this->CreateHitboxComponent(this->sprite, 0, 0, static_cast<float>(this->sprite.getGlobalBounds().width), static_cast<float>(this->sprite.getGlobalBounds().height));
}

Bullet::~Bullet()
{
}

void Bullet::Update(const float& dt)
{
	this->movementComponent->Move(dirX * moveSpeed, dirY * moveSpeed, dt);

	this->hitboxComponent->Update();
}

sf::Vector2f Bullet::GetCollisionPosition()
{
	return this->hitboxComponent->GetPosition();
}

bool Bullet::CheckInterseck(sf::FloatRect frect)
{
	return this->hitboxComponent->CheckIntersect(frect);
}

sf::Vector2f Bullet::GetVelocity()
{
	return this->movementComponent->getVelocity();
}
