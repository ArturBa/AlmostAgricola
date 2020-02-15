//
// Created by bauer on 2/11/20.
//

#include <utility>

#include "Player.hh"

Player::Player(const std::string _name, const int imageId) : imageId(imageId), name{_name} {}

int Player::getImageId() const {
    return imageId;
}

std::string Player::getName() {
    return name;
}
