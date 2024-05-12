#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Keyboard.hpp"

#include "../component/MovementComponent.h"
#include "../component/HitboxComponent.h"
#include "../component/AttackComponent.h"

class Entity
{
private:
	void InitVariables();

protected:
	sf::Sprite sprite;

	HitboxComponent*	hitboxComponent;
	MovementComponent*	movementComponent;
	AttackComponent* attackComponent;

public:
	Entity();
	~Entity();

	//Component Functions
	void SetTexture(sf::Texture& texture);
	void CreateHitboxComponent(sf::Sprite& sprite, const float offset_x, const float offset_y, const float width, const float height);
	void CreateMovementComponent(const float maxVelocity);
	void CreateAttackComponent(const float x, const float y, const float width, const float height);

	//Accessers
	const sf::Vector2f GetPosition() const;
	const sf::Vector2i GetSize() const;
	const sf::FloatRect GetGlobalBounds() const;

	//Functions
	virtual void SetOrigin(const float x, const float y);
	virtual void setPosition(const float x, const float y);
	virtual void Move(const float& dt, const float dir_x, const float dir_y);
	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget& target);
};

#endif // !ENTITY_H