#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{
	switch_held = true;
	player = new Player(sf::Color::Blue, 40, 40, 10, 10);
}

GameState::~GameState()
{
}

void GameState::endState()
{
}

void GameState::pollEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		//std::cout << switch_held << "\n";
		if (!this->switch_held) {
			this->switch_held = true;
			returnState();
		}
	}
	else {
		this->switch_held = false;
		//std::cout << switch_held << "\n";
	}
}

void GameState::update()
{
	player->update();
}

void GameState::render(sf::RenderTarget* target)
{
	target->draw(player->getRenderObject());
}
