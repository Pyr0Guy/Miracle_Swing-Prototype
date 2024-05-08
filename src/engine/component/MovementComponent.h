#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"


class MovementComponent
{
	sf::Sprite& sprite;

	sf::Vector2f velocity;
	float maxVelocity;
public:
	MovementComponent(sf::Sprite& sprite,  float maxVelocity);
	~MovementComponent();

	//Fucktions
	void Move(const float dir_x, const float dir_y, const float dt);
	void Update(const float& dt);

	//Accsesors
	const sf::Vector2f& getVelocity() const;
};

#endif // !MOVEMENTCOMPONENT_H