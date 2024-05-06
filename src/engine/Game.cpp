#include "Game.h"

//------------------------------Init stuff--------------------------------
void Game::InitWindow()
{
	// Reading config for Window

	std::ifstream ifs("config/window.miracle");

	std::string title = "None";
	sf::VideoMode windowBounds(800, 600);
	unsigned int FPSLimit = 60;
	bool VSEnable = false;

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> windowBounds.width >> windowBounds.height;
		ifs >> FPSLimit;
		ifs >> VSEnable;
	}

	ifs.close();

	this->window = new sf::RenderWindow(windowBounds, title);
	this->window->setFramerateLimit(FPSLimit);
	this->window->setVerticalSyncEnabled(VSEnable);
	this->GameIsRunning = true;
}

void Game::InitKeys()
{
	std::ifstream ifs("config/fuckingKeys.miracle");

	if (ifs.is_open())
	{
		std::string key = "";
		int keyValue = 0;

		while (ifs >> key >> keyValue)
			this->supportedKeys[key] = keyValue;
	}

	ifs.close();
}

void Game::InitState()
{
	this->states.push(new GameState(this->window, &this->supportedKeys, &this->states));
}

//-----------------------------Constructor / Destructor-----------------------------
Game::Game()
{
	this->InitWindow();
	this->InitKeys();
	this->InitState();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

//-----------------------------Functions-----------------------------
void Game::UpdateDT()
{
	//Update delta time
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::HandleEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->GameIsRunning = false;
	}
}

void Game::Update()
{
	this->HandleEvents();

	if (!this->states.empty())
	{
		this->states.top()->Update(this->dt);

		if (this->states.top()->getQuit())
		{
			this->states.top()->EndState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		//Aplication fucking end
		this->GameIsRunning = false;
	}
}

void Game::Render()
{
	this->window->clear(sf::Color::Magenta);

	if (!this->states.empty())
		this->states.top()->Render(this->window);

	this->window->display();
}

void Game::Run()
{
	while (this->GameIsRunning)
	{
		this->UpdateDT();
		this->Update();
		this->Render();
	}
}

/* */