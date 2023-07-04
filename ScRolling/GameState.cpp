#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
	:State(window, states)
{
	switch_held = true;
	level = new GameLevel(1);
	game_objects = level->getGameObjects();
	collision_objects = level->getCollisionObjects();
	player = new Player(sf::Color::Blue, level->getStartPosition(), level->getStartRadius(), level->getStartVelocity());
}

GameState::~GameState()
{
}

bool GameState::checkCollision()
{
	bool collision = false;
	for (auto& element : *collision_objects) {
		sf::FloatRect area;
		if (player->getRenderObject().getGlobalBounds().intersects(element->object.getGlobalBounds(), area)) {
			if (area.width > area.height)
			{
				player->exitFreeFall();
				if (area.contains({ area.left, player->getRenderObject().getPosition().y }))
				{
					// Up side crash
					player->setPosition(player->getRenderObject().getPosition().x, player->getRenderObject().getPosition().y + area.height);
					player->bump();
				}
				else
				{
					// Down side crash
					player->setPosition(player->getRenderObject().getPosition().x, player->getRenderObject().getPosition().y - area.height);
					player->bump();
				}
			}
			else if (area.width < area.height)
			{
				if (area.contains({ player->getRenderObject().getPosition().x 
					+ player->getRenderObject().getGlobalBounds().width - 1.f, area.top + 1.f }))
				{
					//Right side crash
					player->setPosition(player->getRenderObject().getPosition().x - area.width, player->getRenderObject().getPosition().y);
					player->reverse();
				}
				else
				{
					//Left side crash
					player->setPosition(player->getRenderObject().getPosition().x + area.width, player->getRenderObject().getPosition().y);
					player->reverse();
				}
			}
			
		}
	}
	return collision;
}

void GameState::pollEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		//std::cout << switch_held << "\n";
		if (!this->switch_held) {
			this->switch_held = true;
			returnState();
		}
	}
	else {
		this->switch_held = false;
		//std::cout << switch_held << "\n";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (!this->jump_held) {
			this->jump_held = true;
			player->jump();
		}
	}
	else {
		this->jump_held = false;
	}
}

void GameState::update()
{
	player->update();
	checkCollision();
}

void GameState::render(sf::RenderTarget* target)
{
	for (auto & element : *game_objects) {
		target->draw(element->object);
	}
	target->draw(player->getRenderObject());
}
