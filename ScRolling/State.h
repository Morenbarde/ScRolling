#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <stack>

class State
{
private:
protected: 
	std::stack<State*>* states;
	sf::RenderWindow* window;

	void returnState();
	void pushState(State* state);

public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();

	virtual void pollEvents(sf::Event event) = 0; //pure virtual, need to be defined in child class
	virtual void update() = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};
