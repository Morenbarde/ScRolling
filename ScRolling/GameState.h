#pragma once

#include "State.h"
#include "Player.h"
#include "GameLevel.h"

class GameState :
    public State
{
private:
    int MAX_LEVELS = 5;


    Player* player;
    GameLevel* level;
    std::vector<RECTOBJECT_T*>* game_objects;
    std::vector<RECTOBJECT_T*>* collision_objects;

    dir direction = ndir;

    int current_level;

    sf::Clock collision_clock;
    sf::Time collision_time;
    float time_to_free_fall = 0.05;

    bool level_ended = false;
    sf::Font font;
    sf::Text end_text;

    bool is_jumping = false;

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states, int level);
    virtual ~GameState();

    //functions
    void loadLevel();
    bool checkCollision();

    //Updates
    void pollEvents(sf::Event event);
    void update();
    void render(sf::RenderTarget* target = nullptr);
};

