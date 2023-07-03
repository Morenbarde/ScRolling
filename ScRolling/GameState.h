#pragma once

#include "State.h"
#include "Player.h"

class GameState :
    public State
{
private:
    Player* player;
public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    void endState();

    //Updates
    void pollEvents();
    void update();
    void render(sf::RenderTarget* target = nullptr);
};

