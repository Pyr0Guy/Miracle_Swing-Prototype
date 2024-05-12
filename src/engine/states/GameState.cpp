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
	if (!this->textures["PLAYER_BALL"].loadFromFile("assets/images/textures/stupid.png"))
		throw "ERROR::GAME_STATE::CANT_LOAD_PLAYER_ATACK_TEXTURE";
	if (!this->textures["PLAYER_ENEMY"].loadFromFile("assets/images/textures/osakaEnemy.jpg"))
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

	//this->bVector.push_back(new Bullet(this->textures["PLAYER_BALL"], window->getSize().x / 2, 200, 0.f, 1.f));
	this->enemy = new Enemy(this->textures["PLAYER_ENEMY"], window->getSize().x / 2, 100.f);
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

	//Player hitbox Check

	for (size_t i = 0; i < this->bVector.size(); i++)
	{
		if (this->bVector[i]->CheckInterseck(this->player->GetGlobalBounds()))
		{
			this->EndState();
		}

		if (this->bVector[i]->GetPosition().x >= this->window->getSize().x || this->bVector[i]->GetPosition().x <= 0 ||
			this->bVector[i]->GetPosition().y >= this->window->getSize().y || this->bVector[i]->GetPosition().y <= 0)
		{
			this->bVector.erase(this->bVector.begin() + i);
		}
	}
	
	//Player Hitbox Attack Check
	if (this->player->isAtacking)
	{
		for (size_t i = 0; i < this->bVector.size(); i++)
		{
			if (this->bVector[i]->CheckInterseck(this->player->GetCollisionBounds()))
			{
				sf::FloatRect plRect = this->player->GetCollisionBounds();
				sf::FloatRect blRect = this->bVector[i]->GetGlobalBounds();

				//This is stupid
				if ((plRect.left + plRect.width) <= blRect.left + blRect.width)
					this->bVector[i]->dirX = 1;
				else
					this->bVector[i]->dirX = -1;

				this->bVector[i]->dirY = -1;
			}
		}
	}

	if (this->enemy->spawnTimer <= 0)
	{
		this->bVector.push_back(new Bullet(this->textures["PLAYER_BALL"], this->enemy->GetPosition().x, this->enemy->GetPosition().y + (this->enemy->GetSize().y / 2), 0, 1));
		this->enemy->spawnTimer = 0.5f;
	}

	this->player->Update(dt);
	this->enemy->Update(dt);

	for (auto& b : this->bVector)
		b->Update(dt);
}

void GameState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->player->Render(*target);

	for (auto& b : this->bVector)
		b->Render(*target);

	this->enemy->Render(*target);
}

/* */