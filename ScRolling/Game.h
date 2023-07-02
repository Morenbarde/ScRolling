#pragma once

#include "MenuState.h"

class Game
{
private:
	sf::VideoMode video_mode;
	sf::RenderWindow* window;
	int window_height = 600;
	int window_width = 1000;

	sf::Event event;
	
	bool running;

	std::stack<State*> states;

	//Initializers
	void initWindow();
	void initStates();

public:
	Game();
	~Game();

	//Getters
	bool isRunning();
	
	//Game Functions
	void pollEvents();
	void update();
	void render();
};

