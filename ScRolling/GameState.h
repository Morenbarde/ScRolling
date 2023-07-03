#pragma once

#include "State.h"
#include "Player.h"
#include "GameLevel.h"

class GameState :
    public State
{
private:
    Player* player;
    GameLevel* level;
    std::vector<RECTOBJECT_T*>* game_objects = nullptr;
    std::vector<RECTOBJECT_T*>::iterator iter;
public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    void endState();

    //Updates
    void pollEvents();
    void update();
    void render(sf::RenderTarget* target = nullptr);
};

