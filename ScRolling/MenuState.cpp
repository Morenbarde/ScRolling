#include "MenuState.h"
MenuState::MenuState(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{
}

MenuState::~MenuState()
{
}

void MenuState::endState()
{
}

void MenuState::pollEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		pushState(new GameState(this->window, this->states));
	}
}

void MenuState::update()
{
	std::cout << "Hello from MenuState \n";
}

void MenuState::render(sf::RenderTarget* target)
{
}
