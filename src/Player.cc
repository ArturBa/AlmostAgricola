//
// Created by bauer on 2/11/20.
//
#include <utility>

#include "Player.hh"

Player::Player(std::string _name, const int imageId) : imageId(imageId), name{std::move(_name)} {}

int Player::getImageId() const {
    return imageId;
}

std::string Player::getName() const {
    return name;
}
