//
// Created by bauer on 2/11/20.
//
#include <utility>

#include "Player.hh"

Player::Player(std::string _name, PlayerTexture *playerTexture) : texture(playerTexture), name{std::move(_name)} {
    farm[0][0] = farm[0][1] = FarmEnum::ClayHouse;
}

const PlayerTexture *Player::getTexture() const {
    return texture;
}

std::string Player::getName() const {
    return name;
}

std::array<std::array<FarmEnum, FARM_WIDTH>, FARM_HEIGHT> Player::getFarm() {
    return farm;
}

