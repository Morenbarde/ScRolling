#include "Player.h"
#include <iostream>

Player::Player(sf::Color color, float x, float y, float radius, float x_velocity)
{
	render_object.setFillColor(color);
	position.x = x;
	position.y = y;
	render_object.setPosition(position);

	render_object.setRadius(radius);
	this->radius = radius;

	velocity.x = x_velocity;
	velocity.y = 0;
}

Player::~Player()
{
	delete this;
}

sf::CircleShape Player::getRenderObject()
{
	return this->render_object;
}

void Player::update()
{
	update_time = update_clock.getElapsedTime();
	if (update_time.asSeconds() >= (1.0 / 60.0)) {
		this->roll();
		render_object.setPosition(position);
		update_clock.restart();
	}
}

void Player::roll()
{
	//velocity == m/s
	//10 p == 1 m

	position.x += velocity.x/6;
}
