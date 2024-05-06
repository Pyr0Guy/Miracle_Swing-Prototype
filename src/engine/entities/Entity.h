#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Window/Keyboard.hpp"

class Entity
{
protected:
	sf::RectangleShape shape;
	float movementSpeed;

public:
	Entity();

	//Functions
	virtual void Move(const float& dt, const float dir_x, const float dir_y);
	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);
};

#endif // !ENTITY_H