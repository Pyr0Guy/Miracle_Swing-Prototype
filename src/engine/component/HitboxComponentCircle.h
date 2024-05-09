#ifndef HITBOXCOMPONENTCIRCLE
#define HITBOXCOMPONENTCIRCLE

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Sprite.hpp"

class HitboxComponentCircle
{
	sf::Sprite& sprite;
	sf::CircleShape hitbox;

	float offsetX;
	float offsetY;
public:
	HitboxComponentCircle(sf::Sprite& sprite, float offset_x, float offset_y, float radius, sf::Color hiboxColor = sf::Color::Green);
	~HitboxComponentCircle();

	//Functions
	bool CheckIntersect(const sf::FloatRect& frect);

	void Update();
	void Render(sf::RenderTarget& target);
};

#endif // !HITBOXCOMPONENTCIRCLE