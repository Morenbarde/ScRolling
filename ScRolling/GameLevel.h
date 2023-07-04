#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

enum dir {ndir = 0, up, right, down, left};

typedef struct {
	sf::RectangleShape object;
	bool collision;
} RECTOBJECT_T;

class GameLevel
{
private:
	std::vector<RECTOBJECT_T*> game_objects;
	std::vector<RECTOBJECT_T*> collision_objects;
	int level;
	std::string level_string;
	std::string line_string;
	std::string data_string;

	sf::Vector2f start_position;
	float start_velocity;
	float start_radius;

	RECTOBJECT_T* obj;

	float x, y, width, height;
	int r, g, b;
	int col;
public:
	GameLevel(int level);
	~GameLevel();

	//getters
	std::vector<RECTOBJECT_T*>* getGameObjects();
	std::vector<RECTOBJECT_T*>* getCollisionObjects();
	sf::Vector2f getStartPosition();
	float getStartRadius();
	float getStartVelocity();

	void readLevel();
};

