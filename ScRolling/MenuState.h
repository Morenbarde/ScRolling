#pragma once

#include "State.h"
#include "GameState.h"

class MenuState :
    public State
{
private:
    int chosen_level = 1;
public:
    MenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~MenuState();

    //functions
    void openGame(int level);

    void pollEvents();
    void update();
    void render(sf::RenderTarget* target = nullptr);
};

