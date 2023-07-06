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
	std::cout << "Message 1";
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		std::cout << "Message 2";
		switch (event.key.code) {

		case sf::Keyboard::Tab:
			std::cout << "Message 3";
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
