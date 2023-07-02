#include "Game.h"

void Game::initWindow()
{

	video_mode.height = window_height;
	video_mode.width = window_width;
	window = new sf::RenderWindow(video_mode, "ScRolling", sf::Style::Default);
}

void Game::initStates()
{
	states.push(new MenuState(this->window, &this->states));

}

Game::Game()
{
	running = true;
	initWindow();
	initStates();
}

Game::~Game()
{
	running = false;
	delete this->window;
	while (!states.empty()) {
		delete this->states.top();
		states.pop();
	}
}

bool Game::isRunning()
{
	return running;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			window->close();
			//running = false;
			break;
		}
	}
	if (!states.empty()) {
		states.top()->pollEvents();
	}
}

void Game::update()
{
	if (!states.empty()) {
		states.top()->update();
	}
}

void Game::render()
{
	window->clear(sf::Color::Black);

	if (!states.empty()) {
		states.top()->render(this->window);
	}

	window->display();
}
