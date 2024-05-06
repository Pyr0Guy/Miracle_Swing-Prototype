#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "../entities/Entity.h"

class GameState : public State
{
	Entity player;

	//Functions
	void InitKeybinds();
public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	~GameState();

	//Functions 
	void EndState();
	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target = nullptr);
};

#endif // !GAMESTATE_H