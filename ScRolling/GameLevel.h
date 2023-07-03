#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

typedef struct {
	sf::RectangleShape object;
	bool collision;
} RECTOBJECT_T;

class GameLevel
{
private:
	std::vector<RECTOBJECT_T*> game_objects;
	int level;
	std::string level_string;
	std::string line_string;
	std::string data_string;

	sf::Vector2f start_position;
	float start_velocity;
	float start_radius;

	float x, y, x2, y2;
	int r, g, b;
	int col;
public:
	GameLevel(int level);
	~GameLevel();

	//getters
	std::vector<RECTOBJECT_T*>* getGameObjects();
	sf::Vector2f getStartPosition();
	float getStartRadius();
	float getStartVelocity();

	void readLevel();
};

