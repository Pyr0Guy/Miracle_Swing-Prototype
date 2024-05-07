#ifndef STATE_H
#define STATE_H

#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <fstream>

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Window/Keyboard.hpp"

class State
{
protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedkeys;
	std::map<std::string, int>  keybinds;
	bool quit;

	//Resourses
	std::map<std::string, sf::Texture> textures;

	//Functuions
	virtual void InitKeybinds() = 0;
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~State();

	const bool& getQuit() const;

	void EndState();
	virtual void UpdateInput(const float& dt) = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target = nullptr) = 0;
};

#endif // !STATE_H