#include "AttackComponent.h"

void AttackComponent::InitVariables()
{
	this->timeToLive = 0.5f;
	this->destroyYourselfNOW = false;
}

void AttackComponent::InitComponents(sf::Sprite& sprite, float x, float y, const float width, const float height)
{
	this->attackHitbox = new HitboxComponent(sprite, x, y, width, height, sf::Color::Red);
}

AttackComponent::AttackComponent(sf::Sprite& sprite, float x, float y, const float width, const float height)
{
	this->InitVariables();
	this->InitComponents(sprite, x, y, width, height);
}

AttackComponent::~AttackComponent()
{
	delete attackHitbox;
}

HitboxComponent* AttackComponent::GetHitbox()
{
	return this->attackHitbox;
}

void AttackComponent::Update(float dt)
{
	if (this->destroyYourselfNOW == false)
	{
		this->attackHitbox->Update();

		/* TODO: When i code bullet make collision check for AttackComponent --09.05.2024
		if (this->attackHitbox->CheckIntersect(bullet))
		{

		}
		*/

		if (this->timeToLive <= 0)
		{
			this->destroyYourselfNOW = true;
		}

		this->timeToLive -= 1 * dt;
	}
}

void AttackComponent::Render(sf::RenderTarget& target)
{
	this->attackHitbox->Render(target);
}

/* */