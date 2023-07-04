#pragma once

#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::CircleShape render_object;
	sf::Vector2f position;
	sf::Vector2f velocity;
	float acceleration = -.98;
	float radius;
	float jump_strength = 40.0;

	bool free_fall = true;

	sf::Clock update_clock;
	sf::Time update_time;
public:
	Player(sf::Color color, sf::Vector2f position, float radius, float x_velocity);
	~Player();

	//setters
	void setPosition(float x, float y);

	//getters
	sf::CircleShape getRenderObject();
	float getRadius();
	sf::Vector2f getVelocity();

	void update();
	
	//functions
	void updatePosition();
	void reverse();
	void bump();
	void jump();
	void enterFreeFall();
	void exitFreeFall();
};

