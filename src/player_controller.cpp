#include "player_controller.h"
#include "player.h"
#include "config.h"
#include <SFML/Window/Keyboard.hpp>

PlayerController* PlayerController::controller = nullptr;

PlayerController::~PlayerController() {
    delete controller;
}

void PlayerController::controllPlayer(Player* player, float time) {
    sf::Vector2f updated_pos = player->getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        updated_pos.x -= PLAYER_SPEED * time;
        player->setState(State::RUN);
        player->setDirection(Direction::LEFT);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        updated_pos.x += PLAYER_SPEED * time;
        player->setState(State::RUN);
        player->setDirection(Direction::RIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        updated_pos.y -= PLAYER_SPEED * time;
        player->setState(State::RUN);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        updated_pos.y += PLAYER_SPEED * time;
        player->setState(State::RUN);
    }

    player->setPosition(updated_pos);
}
