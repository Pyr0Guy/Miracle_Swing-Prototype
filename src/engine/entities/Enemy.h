#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include <cmath>

class Enemy
	: public Entity
{
	int counter;
	int amplitude;
	int speed;
	float radians;

	float x, y;
public:
	Enemy(sf::Texture& texture, float x, float y);
	~Enemy();

	float spawnTimer;

	void Update(const float& dt);
};

#endif // !ENEMY_H