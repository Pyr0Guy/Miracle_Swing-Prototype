#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Event.hpp"

#include <fstream>
#include <map>
#include <stack>
#include <string>

#include "states/State.h"
#include "states/GameState.h"

class Game
{
	//Variables
	sf::RenderWindow* window;
	sf::Event ev;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	//in SFML all keyboard keys are ENUM - int
	std::map<std::string, int> supportedKeys;

	//Functions
	void InitWindow();
	void InitKeys();
	void InitState();
public:
	Game();
	~Game();

	//Public Functions
	void UpdateDT();
	void HandleEvents();
	void Update();
	void Render();
	void Run();
	
	//Public Variables
	bool GameIsRunning;
};

#endif // GAME_H
