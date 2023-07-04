#include "MenuState.h"
MenuState::MenuState(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{
	switch_held = true;
}

MenuState::~MenuState()
{
}
void MenuState::pollEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		if (!this->switch_held) {
			this->switch_held = true;
			pushState(new GameState(this->window, this->states));
		}
	} else {
		this->switch_held = false;
	}
}

void MenuState::update()
{
	std::cout << "Hello from MenuState \n";
}

void MenuState::render(sf::RenderTarget* target)
{
}
