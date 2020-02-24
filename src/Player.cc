//
// Created by bauer on 2/11/20.
//
#include <utility>

#include "Player.hh"

Player::Player(std::string _name, PlayerTexture *playerTexture) : texture(playerTexture), name{std::move(_name)} {
    sheep = 0,
            food = 2;
    farm[0][0] = farm[0][1] = FarmEnum::ClayHouse;
}

const PlayerTexture *Player::getPlayerTexture() const {
    return texture;
}

std::string Player::getName() const {
    return name;
}

std::array<std::array<FarmEnum, FARM_WIDTH>, FARM_HEIGHT> Player::getFarm() {
    return farm;
}

unsigned int Player::getSheep() const {
    return sheep;
}

unsigned int Player::getFood() const {
    return food;
}

void Player::addSheep(unsigned int sheepNo) {
    sheep += sheepNo;
}

void Player::transformSheepIntoFood(unsigned int sheepNo) {
    sheep--;
    if (std::find(upgrades.begin(), upgrades.end(), UpgradeEnum::Kitchen_2) != upgrades.end() ||
        std::find(upgrades.begin(), upgrades.end(), UpgradeEnum::Kitchen_3) != upgrades.end()) {
        food += 4 * sheepNo;
    } else if (std::find(upgrades.begin(), upgrades.end(), UpgradeEnum::Kitchen_0) != upgrades.end() ||
               std::find(upgrades.begin(), upgrades.end(), UpgradeEnum::Kitchen_1) != upgrades.end()) {
        food += 3 * sheepNo;
    } else {
        food += 2 * sheepNo;
    }
}

void Player::addUpgrade(UpgradeEnum upgrade) {
    upgrades.push_back(upgrade);
}

