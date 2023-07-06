#include "Game.h"

void Game::initVariables()
{
	font.loadFromFile("Blacklisted.ttf");

	this->game_info.setFont(font);
	this->game_info.setString("");
	this->game_info.setCharacterSize(20);
	this->game_info.setStyle(sf::Text::Bold);
	this->game_info.setPosition(50, 30);
}

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
	initVariables();
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
		case sf::Event::KeyPressed:
			switch (this->event.key.code) {
			case sf::Keyboard::F3:
				show_game_info = !show_game_info;
				break;
			}
		}
		if (!states.empty()) {
			states.top()->pollEvents(this->event);
		}
	}
}

void Game::update()
{
	if (!states.empty()) {
		states.top()->update();
	}

	frame_counter += 1;
	dt = fps_clock.getElapsedTime();
	if (dt.asSeconds() >= 1) {
		fps = frame_counter;
		frame_counter = 0;
		fps_clock.restart();
		this->game_info.setString("FPS: " + std::to_string(fps));
	}
}

void Game::render()
{
	window->clear(sf::Color::Black);

	if (!states.empty()) {
		states.top()->render(this->window);
	}

	if (show_game_info) {
		window->draw(game_info);
	}

	window->display();
}
