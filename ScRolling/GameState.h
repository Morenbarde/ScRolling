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

    sf::Clock collision_clock;
    sf::Time collision_time;
    float time_to_free_fall = 0.05;

    bool level_ended = false;

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states, int level);
    virtual ~GameState();

    //functions
    void loadLevel(int l);
    bool checkCollision();

    //Updates
    void pollEvents();
    void update();
    void render(sf::RenderTarget* target = nullptr);
};

