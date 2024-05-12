#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "../entities/Player.h"
#include "../entities/Entity.h"
#include "../entities/Bullet.h"
#include "../entities/Enemy.h"

#include <vector>

class GameState : public State
{
	Player* player;
	bool pressed;
	bool hold;

	Enemy* enemy;
	std::vector<Bullet*> bVector;

	//Functions
	void InitKeybinds();
	void InitTextures();
	//Co-op maybe?!?!?!?!?
	void InitPlayers(sf::RenderWindow& window);

	bool CheckForPressedKey(int key);
public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	~GameState();

	//Functions 
	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target = nullptr);
};

#endif // !GAMESTATE_H