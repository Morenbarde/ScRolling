#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, int level)
	:State(window, states)
{
	switch_held = true;
	loadLevel(level);
	game_objects = this->level->getGameObjects();
	collision_objects = this->level->getCollisionObjects();
	player = new Player(sf::Color::Blue, this->level->getStartPosition(), 
		this->level->getStartRadius(), this->level->getStartVelocity());
}

GameState::~GameState()
{
}

void GameState::loadLevel(int l)
{
	level = new GameLevel(l);
	level_ended = false;
}

bool GameState::checkCollision()
{
	bool collision = false;
	
	if (player->getRenderObject().getGlobalBounds().intersects(level->getLevelEnding().getGlobalBounds()) && !level_ended) {
		std::cout << "Level Completed!";
		level_ended = true;
	} else {
		for (auto& element : *collision_objects) {
			sf::FloatRect area;
			if (player->getRenderObject().getGlobalBounds().intersects(element->object.getGlobalBounds(), area)) {
				collision = true;
				if (area.width > area.height)
				{
					if (area.contains({ area.left, player->getRenderObject().getPosition().y }) && player->getVelocity().y >= 0)
					{
						// Up side crash
						player->setPosition(player->getRenderObject().getPosition().x,
							player->getRenderObject().getPosition().y + area.height);
						player->bump();
					}
					else if (player->getVelocity().y < 0)
					{
						// Down side crash
						player->setPosition(player->getRenderObject().getPosition().x,
							player->getRenderObject().getPosition().y - area.height);
						player->bump();
						player->exitFreeFall();
						collision_clock.restart();
					}
				}
				else if (area.width < area.height)
				{
					if (area.contains({ player->getRenderObject().getPosition().x
						+ player->getRenderObject().getGlobalBounds().width - 1.f, area.top + 1.f })
						&& player->getVelocity().x >= 0)
					{
						//Right side crash
						player->setPosition(player->getRenderObject().getPosition().x - area.width,
							player->getRenderObject().getPosition().y);
						player->reverse();
					}
					else if (area.contains({ player->getRenderObject().getPosition().x + 1.f, area.top + 1.f })
						&& player->getVelocity().x < 0)
					{
						//Left side crash
						player->setPosition(player->getRenderObject().getPosition().x + area.width,
							player->getRenderObject().getPosition().y);
						player->reverse();
					}
				}

			}
		}
		if (collision_clock.getElapsedTime().asSeconds() >= time_to_free_fall) {
			player->enterFreeFall();
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
		if (!this->jump_held && !level_ended) {
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
