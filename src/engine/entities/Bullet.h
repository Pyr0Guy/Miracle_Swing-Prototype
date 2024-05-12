#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

#include "../component/MovementComponent.h"
#include "../component/HitboxComponent.h"

class Bullet
	: public Entity
{
	
public:
	Bullet(sf::Texture& texture, const float x, const float y, float dirX, float dirY, float moveSpeed = 10.f);
	~Bullet();

	float dirX, dirY, moveSpeed;

	void Update(const float& dt);
	sf::Vector2f GetCollisionPosition();
	bool CheckInterseck(sf::FloatRect frect);
	sf::Vector2f GetVelocity();
};

#endif // !BULLET_H