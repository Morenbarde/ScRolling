#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, int level)
	:State(window, states)
{	
	this->current_level = level;
	loadLevel();

	font.loadFromFile("Blacklisted.ttf");
	end_text.setFont(font);
	end_text.setString("Level Completed!");
	end_text.setCharacterSize(60);
	end_text.setStyle(sf::Text::Bold);
	end_text.setPosition(660, 370);
}

GameState::~GameState()
{
}

void GameState::loadLevel()
{
	level_ended = false;
	level = new GameLevel(this->current_level);
	game_objects = this->level->getGameObjects();
	collision_objects = this->level->getCollisionObjects();
	player = new Player(sf::Color::Blue, this->level->getStartPosition(), this->level->getStartRadius(), this->level->getStartVelocity());
}

bool GameState::checkCollision()
{
	bool collision = false;
	
	if (player->getRenderObject().getGlobalBounds().intersects(level->getLevelEnding().getGlobalBounds()) && !level_ended) {
		level_ended = true;
		is_jumping = false;
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

void GameState::pollEvents(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		switch (event.key.code) {

		case sf::Keyboard::Tab:
			returnState();
			break;

		case sf::Keyboard::Space:
			if (!level_ended) {
				is_jumping = true;
			}
			else {
				if (current_level < MAX_LEVELS) {
					this->current_level += 1;
					loadLevel();
				}
				else {
					returnState();
				}
			}
			break;

		case sf::Keyboard::R:
			level_ended = false;
			loadLevel();
			break;
		}
		break;

	case sf::Event::KeyReleased:
		switch (event.key.code) {

			case sf::Keyboard::Space:
				is_jumping = false;
				break;
		}
		break;
	}
}

void GameState::update()
{
	if (is_jumping) {
		player->jump();
	}
	player->update();
	checkCollision();
}

void GameState::render(sf::RenderTarget* target)
{
	for (auto & element : *game_objects) {
		target->draw(element->object);
	}
	target->draw(player->getRenderObject());
	if (level_ended) {
		target->draw(end_text);
	}
}
