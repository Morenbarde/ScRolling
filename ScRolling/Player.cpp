#include "Player.h"
#include <iostream>

Player::Player(sf::Color color, sf::Vector2f position, float radius, float x_velocity)
{
	render_object.setFillColor(color);
	render_object.setPosition(position);

	render_object.setRadius(radius);
	this->radius = radius;

	this->position = position;
	velocity.x = x_velocity;
	velocity.y = 0;
}

Player::~Player()
{
	delete this;
}

void Player::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	render_object.setPosition(position);
}

sf::CircleShape Player::getRenderObject()
{
	return this->render_object;
}

float Player::getRadius()
{
	return this->radius;
}

sf::Vector2f Player::getVelocity()
{
	return this->velocity;
}

void Player::update()
{
	update_time = update_clock.getElapsedTime();
	if (update_time.asSeconds() >= (1.0 / 60.0)) {
		this->updatePosition();

		render_object.setPosition(position);
		update_clock.restart();
	}
}

void Player::updatePosition()
{
	//velocity == m/s
	//10 p == 1 m
	position.x += velocity.x / 6;
	position.y -= velocity.y / 6;

	velocity.y += acceleration;
}

void Player::reverse()
{
	velocity.x *= -1;
}

void Player::bump()
{
	velocity.y = 0;
}

void Player::jump()
{
	if (!free_fall) {
		velocity.y = jump_strength;
		enterFreeFall();
	}
}

void Player::enterFreeFall()
{
	free_fall = true;
}

void Player::exitFreeFall()
{
	free_fall = false;
}
