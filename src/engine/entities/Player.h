#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

#include <cmath>

class Player :
	public Entity
{
	//Variables
	float originX;
	float originY;

	float attackCooldown;

	//Initilizer functions
	void InitVariables();
	void InitComponent();

	//Functions
	void UpdateAttack(const float& dt);
public:
	Player(float x, float y, sf::Texture& texture, const float originX = 0, const float originY = 0);
	~Player();

	//Variables
	bool isAtacking;
	bool canAttack;

	bool CheckCollision(const sf::FloatRect& frect);
	sf::FloatRect GetCollisionBounds();

	void Update(const float& dt);
};

#endif // !PLAYER_H