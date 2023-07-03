#pragma once

#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::CircleShape render_object;
	sf::Vector2f position;
	sf::Vector2f velocity;
	float radius;

	sf::Clock update_clock;
	sf::Time update_time;
public:
	Player(sf::Color color, float x, float y, float radius, float x_velocity);
	~Player();

	//getters
	sf::CircleShape getRenderObject();

	void update();
	
	//functions
	void roll();
};

