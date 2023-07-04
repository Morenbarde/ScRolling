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
    std::vector<RECTOBJECT_T*>* game_objects;
    std::vector<RECTOBJECT_T*>* collision_objects;

    dir direction = ndir;

    bool jump_held = false;

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    //functions
    bool checkCollision();

    //Updates
    void pollEvents();
    void update();
    void render(sf::RenderTarget* target = nullptr);
};

