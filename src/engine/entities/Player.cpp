#include "Player.h"

//------------------------------Init stuff--------------------------------
void Player::InitVariables()
{
	this->isAtacking = false;
	this->canAttack = true;
	this->attackCooldown = 0.5f;
}

void Player::InitComponent()
{
	this->CreateMovementComponent(100.f);
	this->CreateHitboxComponent(this->sprite, 24.f - originX, 42.f - originY, 10.f, 10.f);
}

//-----------------------------Constructor / Destructor-----------------------------
Player::Player(float x, float y, sf::Texture& texture, const float originX, const float originY)
	: originX(originX),
	  originY(originY)
{
	this->InitVariables();
	this->InitComponent();

	this->SetTexture(texture);

	this->SetOrigin(originX, originY);
	this->setPosition(x, y);
}

Player::~Player()
{
}

//-----------------------------Functions-----------------------------
void Player::UpdateAttack(const float& dt)
{
	if (this->isAtacking == true)
	{
		if (this->attackComponent == nullptr)
		{
			this->attackComponent = new AttackComponent(this->sprite, -originX - 5.f, -originY - 5.f,
				static_cast<float>(this->sprite.getTextureRect().width + 10),
				static_cast<float>(this->sprite.getTextureRect().height + 5));
		}

		this->attackComponent->Update(dt);

		if (this->attackComponent->destroyYourselfNOW == true)
		{
			this->canAttack = false;
			this->isAtacking = false;
			this->attackComponent = nullptr;
			this->attackCooldown = 0.5f;
		}

	}

	if (this->canAttack == false)
	{
		if (this->attackCooldown <= 0.f)
		{
			this->canAttack = true;
		}

		this->attackCooldown -= 1.f * dt;
	}
}

void Player::Update(const float& dt)
{
	if (this->hitboxComponent)
		this->hitboxComponent->Update();

	this->UpdateAttack(dt);

}

/* */