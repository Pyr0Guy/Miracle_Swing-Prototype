#include "Player.h"

//------------------------------Init stuff--------------------------------
void Player::InitVariables()
{
}

void Player::InitComponent()
{
	this->CreateMovementComponent(100.f);
	this->CreateHitboxComponent(this->sprite, 24.f, 42.f, 10.f, 10.f);
}

//-----------------------------Constructor / Destructor-----------------------------
Player::Player(float x, float y, sf::Texture& texture)
{
	this->InitVariables();
	this->setPosition(x, y);

	this->InitComponent();

	this->SetTexture(texture);
}

Player::~Player()
{
}

//-----------------------------Functions-----------------------------
void Player::Update(const float& dt)
{
	this->hitboxComponent->Update();
}

/* */