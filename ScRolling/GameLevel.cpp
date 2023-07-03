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
			level_file >> x >> y >> x2 >> y2 >> r >> g >> b >> col;
			rect.setPosition(x, y);
			rect.setSize(sf::Vector2f((x2 - x), (y2 - y)));
			rect.setFillColor(sf::Color(r, g, b, 255));
			
			RECTOBJECT_T* obj = new RECTOBJECT_T;
			obj->object = rect;
			obj->collision = col;
			game_objects.push_back(obj);
		}
	}
	
}
