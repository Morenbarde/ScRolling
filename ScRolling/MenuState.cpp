#include "MenuState.h"
MenuState::MenuState(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{
	switch_held = true;
}

MenuState::~MenuState()
{
}
void MenuState::openGame(int level)
{
	pushState(new GameState(this->window, this->states, this->chosen_level));
}
void MenuState::pollEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		if (!this->switch_held) {
			this->switch_held = true;
			openGame(this->chosen_level);
		}
	} else {
		this->switch_held = false;
	}
}

void MenuState::update()
{
}

void MenuState::render(sf::RenderTarget* target)
{
}
