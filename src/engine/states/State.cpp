#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: states(states),
	  window(window),
	  supportedkeys(supportedKeys)
{
	this->quit = false;
}

State::~State()
{
}

void State::Update(const float& dt)
{
}

void State::Render(sf::RenderTarget* target)
{
}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::EndState()
{
	this->quit = true;
}

/* */