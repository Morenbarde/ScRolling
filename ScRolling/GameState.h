#pragma once

#include "State.h"

class GameState :
    public State
{
private:
public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    void endState();

    void pollEvents();
    void update();
    void render(sf::RenderTarget* target = nullptr);
};

