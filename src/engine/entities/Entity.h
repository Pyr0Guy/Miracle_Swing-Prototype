#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Keyboard.hpp"

#include "../component/MovementComponent.h"

class Entity
{
private:
	void InitVariables();

protected:
	sf::Texture* texture;
	sf::Sprite* sprite;

	MovementComponent* movementComponent;

public:
	Entity();
	~Entity();

	//Component Functions
	void CreateSprite(sf::Texture* texture);
	void CreateMovementComponent(const float maxVelocity);

	//Functions
	virtual void setPosition(const float x, const float y);
	virtual void Move(const float& dt, const float dir_x, const float dir_y);
	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);
};

#endif // !ENTITY_H