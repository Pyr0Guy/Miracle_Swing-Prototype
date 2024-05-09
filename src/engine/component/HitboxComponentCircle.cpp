#include "HitboxComponentCircle.h"

HitboxComponentCircle::HitboxComponentCircle(sf::Sprite& sprite, float offset_x, float offset_y, float radius, sf::Color hiboxColor)
	: sprite(sprite),
	offsetX(offset_x),
	offsetY(offset_y)
{
	this->hitbox.setPosition(this->sprite.getPosition().x + offset_x, this->sprite.getPosition().y + offset_y);
	this->hitbox.setRadius(radius);
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(1.f);
	this->hitbox.setOutlineColor(hiboxColor);
}

HitboxComponentCircle::~HitboxComponentCircle()
{
}

bool HitboxComponentCircle::CheckIntersect(const sf::FloatRect& frect)
{
	return this->hitbox.getGlobalBounds().intersects(frect);
}

void HitboxComponentCircle::Update()
{
	this->hitbox.setPosition(this->sprite.getPosition().x + this->offsetX, this->sprite.getPosition().y + this->offsetY);
}

void HitboxComponentCircle::Render(sf::RenderTarget& target)
{
	target.draw(this->hitbox);
}

/* */