#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{
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
				this->returnState();
	}
}

void GameState::update()
{
	std::cout << "Hello from GameState \n";
}

void GameState::render(sf::RenderTarget* target)
{
}
