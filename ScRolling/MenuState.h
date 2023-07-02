#pragma once

#include "State.h"
#include "GameState.h"

class MenuState :
    public State
{
private:
public:
    MenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~MenuState();

    void endState();

    void pollEvents();
    void update();
    void render(sf::RenderTarget* target = nullptr);
};

