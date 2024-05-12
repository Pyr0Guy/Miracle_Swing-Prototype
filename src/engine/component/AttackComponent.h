#ifndef ATTACKCOMPOMEMT_H
#define ATTACKCOMPOMEMT_H

#include "HitboxComponent.h"

#include <iostream>

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

class AttackComponent
{
	//Variables
	float timeToLive;
	HitboxComponent* attackHitbox;

	//Functions 
	void InitVariables();
	void InitComponents(sf::Sprite& sprite, float x, float y, const float width, const float height);

public:
	AttackComponent(sf::Sprite& sprite, float x, float y, const float width, const float height);
	~AttackComponent();

	//Variables
	bool destroyYourselfNOW;
	HitboxComponent* GetHitbox();

	//Functions 
	void Update(float dt);
	void Render(sf::RenderTarget& target);
};

#endif // !ATTACKCOMPOMEMT_H