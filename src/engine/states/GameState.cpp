#include "GameState.h"

void GameState::InitKeybinds()
{
	std::ifstream ifs("assets/config/keybinds.miracle");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string keyValue = "";

		while (ifs >> key >> keyValue)
			this->keybinds[key] = this->supportedkeys->at(keyValue);
	}

	ifs.close();
}

void GameState::InitTextures()
{
	if (!this->textures["PLAYER_IDLE"].loadFromFile("assets/images/textures/player.png"))
		throw "ERROR::GAME_STATE::CANT_LOAD_PLAYER_IDLE_TEXTURE";
	if (!this->textures["PLAYER_ATACK"].loadFromFile("assets/images/textures/playerATAck.png"))
		throw "ERROR::GAME_STATE::CANT_LOAD_PLAYER_ATACK_TEXTURE";
}

void GameState::InitPlayers(sf::RenderWindow& window)
{
	sf::Texture tmpTexture = this->textures["PLAYER_IDLE"];
	this->player = new Player(static_cast<float>(window.getSize().x / 2), static_cast<float>(window.getSize().y - tmpTexture.getSize().y), tmpTexture, static_cast<float>(tmpTexture.getSize().x / 2), static_cast<float>(tmpTexture.getSize().y / 2));
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->InitKeybinds();
	this->InitTextures();
	this->InitPlayers(*window);

	this->pressed = false;
	this->hold = false;
}

GameState::~GameState()
{
}

//TODO: Create Keybord System with KeyPressed, KeyHold and KeyRelease
bool GameState::CheckForPressedKey(int key)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(key)))
	{
		if (this->pressed == false)
		{
			this->pressed = true;
		}

		if (this->hold == true)
		{
			this->pressed = false;
		}

		this->hold = true;
	}
	else
	{
		this->hold = false;
	}

	return this->pressed;

	
}

void GameState::UpdateInput(const float& dt)
{
	//-------------- Player Input -------------------
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["MOVE_RIGHT"])))
		this->player->Move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["MOVE_LEFT"])))
		this->player->Move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["MOVE_UP"])))
		this->player->Move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["MOVE_DOWN"])))
		this->player->Move(dt, 0.f, 1.f);
	
	if (this->CheckForPressedKey(this->keybinds["ATACK"]) && this->player->isAtacking == false && this->player->canAttack == true)
	{
		this->player->isAtacking = true;
		this->player->SetTexture(this->textures["PLAYER_ATACK"]);
	}

	if (this->player->isAtacking == false)
	{
		this->player->SetTexture(this->textures["PLAYER_IDLE"]);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds["CLOSE"])))
		this->EndState();
}

void GameState::Update(const float& dt)
{
	this->UpdateInput(dt);

	this->player->Update(dt);
}

void GameState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->player->Render(*target);
}

/* */