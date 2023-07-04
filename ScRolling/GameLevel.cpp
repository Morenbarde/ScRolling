#include "GameLevel.h"

GameLevel::GameLevel(int level)
{
	this->level = level;
	readLevel();
}

GameLevel::~GameLevel()
{
}

std::vector<RECTOBJECT_T*>* GameLevel::getGameObjects()
{
	return &this->game_objects;
}

std::vector<RECTOBJECT_T*>* GameLevel::getCollisionObjects()
{
	return &this->collision_objects;
}

sf::Vector2f GameLevel::getStartPosition()
{
	return this->start_position;
}

float GameLevel::getStartRadius()
{
	return this->start_radius;
}

float GameLevel::getStartVelocity()
{
	return this->start_velocity;
}

void GameLevel::readLevel()
{
	std::ifstream level_file("Level_" + std::to_string(level) + ".txt");
	if (level_file.is_open()) {
		level_file >> start_position.x >> start_position.y >> start_radius >> start_velocity;
		while (!level_file.eof()) {
			sf::RectangleShape rect;
			level_file >> x >> y >> width >> height >> r >> g >> b >> col;
			rect.setPosition(x, y);
			rect.setSize(sf::Vector2f((width), (height)));
			rect.setFillColor(sf::Color(r, g, b, 255));
			
			obj = new RECTOBJECT_T;
			obj->object = rect;
			obj->collision = col;

			if (col) {
				collision_objects.push_back(obj);
			}

			game_objects.push_back(obj);
		}
	}
	
}
