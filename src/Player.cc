//
// Created by bauer on 2/11/20.
//
#include <utility>

#include "Player.hh"

Player::Player(std::string _name, const int imageId) : imageId(imageId), name{std::move(_name)} {
    farm[0][0] = farm[0][1] = FarmEnum::ClayHouse;
}

int Player::getImageId() const {
    return imageId;
}

std::string Player::getName() const {
    return name;
}

std::array<std::array<FarmEnum, FARM_WIDTH>, FARM_HEIGHT> Player::getFarm() {
    return farm;
}
