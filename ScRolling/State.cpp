#include "State.h"

void State::returnState()
{
	this->states->pop();
}

void State::pushState(State* state)
{
	this->states->push(state);
}

State::State(sf::RenderWindow* window, std::stack<State*>* states)
{
	this->window = window;
	this->states = states;
}

State::~State()
{
}
