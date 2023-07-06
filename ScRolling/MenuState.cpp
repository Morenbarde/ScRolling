#include "MenuState.h"
MenuState::MenuState(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{
}

MenuState::~MenuState()
{
}
void MenuState::openGame(int level)
{
	pushState(new GameState(this->window, this->states, this->chosen_level));
}
void MenuState::pollEvents(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		switch (event.key.code) {

		case sf::Keyboard::Tab:
			openGame(this->chosen_level);
			break;
		}
		break;	
	}
}

void MenuState::update()
{
}

void MenuState::render(sf::RenderTarget* target)
{
}
