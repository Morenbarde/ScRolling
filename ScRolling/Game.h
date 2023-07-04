#pragma once

#include "MenuState.h"

class Game
{
private:
	sf::VideoMode video_mode;
	sf::RenderWindow* window;
	int window_height = 800;
	int window_width = 1800;

	sf::Event event;
	
	bool running;

	std::stack<State*> states;

	sf::Clock fps_clock;
	sf::Time dt;
	int frame_counter = 0;
	int fps;
	sf::Font font;
	sf::Text game_info;

	bool show_game_info = false;

	//Initializers
	void initVariables();
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

