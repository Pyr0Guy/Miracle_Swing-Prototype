#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player :
	public Entity
{
	//Variables

	//Initilizer functions
	void InitVariables();
	void InitComponent();
public:
	Player(float x, float y, sf::Texture* texture);
	~Player();

	void Update(const float& dt);
};

#endif // !PLAYER_H