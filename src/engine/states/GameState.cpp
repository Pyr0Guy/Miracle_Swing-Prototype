#include "GameState.h"

void GameState::InitKeybinds()
{
	std::ifstream ifs("config/keybinds.miracle");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string keyValue = "";

		while (ifs >> key >> keyValue)
			this->keybinds[key] = this->supportedkeys->at(keyValue);
	}

	ifs.close();
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->InitKeybinds();
}

GameState::~GameState()
{
}

void GameState::EndState()
{
}

void GameState::UpdateInput(const float& dt)
{
	this->checkForQuit();

	//-------------- Player Input -------------------
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["MOVE_RIGHT"])))
		this->player.Move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["MOVE_LEFT"])))
		this->player.Move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["MOVE_UP"])))
		this->player.Move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["MOVE_DOWN"])))
		this->player.Move(dt, 0.f, 1.f);
}

void GameState::Update(const float& dt)
{
	this->UpdateInput(dt);

	this->player.Update(dt);
}

void GameState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->player.Render(target);
}

/* */