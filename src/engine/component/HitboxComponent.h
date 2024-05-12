#ifndef HITBOXCOMPONENT_H
#define HITBOXCOMPONENT_H

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Sprite.hpp"

class HitboxComponent
{
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;

	float offsetX;
	float offsetY;
public:
	HitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height, sf::Color hiboxColor = sf::Color::Green);
	~HitboxComponent();

	const sf::Vector2f GetPosition() const;

	//Functions
	bool CheckIntersect(const sf::FloatRect& frect);
	
	sf::FloatRect GetGlobalBounds();

	void Update();
	void Render(sf::RenderTarget& target);
};

#endif // HITBOXCOMPONENT_H