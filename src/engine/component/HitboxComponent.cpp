#include "HitboxComponent.h"

HitboxComponent::HitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height, sf::Color hiboxColor)
	: sprite(sprite),
	offsetX(offset_x),
	offsetY(offset_y)
{
	this->hitbox.setPosition(this->sprite.getPosition().x + offset_x, this->sprite.getPosition().y + offset_y);
	this->hitbox.setSize(sf::Vector2f(width, height));
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(1.f);
	this->hitbox.setOutlineColor(hiboxColor);

}

HitboxComponent::~HitboxComponent()
{
}

const sf::Vector2f HitboxComponent::GetPosition() const
{
	return this->hitbox.getPosition();
}

bool HitboxComponent::CheckIntersect(const sf::FloatRect& frect)
{
	return this->hitbox.getGlobalBounds().intersects(frect);
}

sf::FloatRect HitboxComponent::GetGlobalBounds()
{
	return this->hitbox.getGlobalBounds();
}

void HitboxComponent::Update()
{
	this->hitbox.setPosition(this->sprite.getPosition().x + this->offsetX, this->sprite.getPosition().y + this->offsetY);
}

void HitboxComponent::Render(sf::RenderTarget& target)
{
	target.draw(this->hitbox);
}


/* */