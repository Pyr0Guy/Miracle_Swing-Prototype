#include "Player.h"

//------------------------------Init stuff--------------------------------
void Player::InitVariables()
{
}

void Player::InitComponent()
{
}

//-----------------------------Constructor / Destructor-----------------------------
Player::Player(float x, float y, sf::Texture* texture)
{
	this->InitVariables();
	this->InitComponent();

	this->CreateSprite(texture);
	this->setPosition(x, y);
}

Player::~Player()
{
}

//-----------------------------Functions-----------------------------

/* */