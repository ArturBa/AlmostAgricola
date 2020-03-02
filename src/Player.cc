//
// Created by bauer on 2/11/20.
//
#include <utility>

#include "Player.hh"

Player::Player(std::string _name, PlayerTexture *playerTexture) : texture(playerTexture), name{std::move(_name)} {
    familyMembers = 2;
    warehouse = new Warehouse();
    farm[0][0] = farm[0][1] = FarmEnum::WoodHouse;
}

Player::~Player() {
    delete warehouse;
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

void Player::setFarm(const unsigned int x, const unsigned int y, const FarmEnum fieldType) {
    if (x < FARM_WIDTH && y < FARM_HEIGHT) {
        farm[y][x] = fieldType;
    }
}

bool Player::transformSheepIntoFood(unsigned int sheepNo) {
    warehouse->sheep.decreaseResource(sheepNo);
    if (std::find(upgrades.begin(), upgrades.end(), UpgradeEnum::Kitchen_2) != upgrades.end() ||
        std::find(upgrades.begin(), upgrades.end(), UpgradeEnum::Kitchen_3) != upgrades.end()) {
        warehouse->food.addResource(4 * sheepNo);
    } else if (std::find(upgrades.begin(), upgrades.end(), UpgradeEnum::Kitchen_0) != upgrades.end() ||
               std::find(upgrades.begin(), upgrades.end(), UpgradeEnum::Kitchen_1) != upgrades.end()) {
        warehouse->food.addResource(3 * sheepNo);
    } else {
        warehouse->food.addResource(2 * sheepNo);
    }
}

void Player::addUpgrade(UpgradeEnum upgrade) {
    upgrades.push_back(upgrade);
}

unsigned int Player::getHouseRooms() {
    unsigned int houseRooms = 0;
    for (const auto &y: farm) {
        for (const auto &x: y) {
            if (x == FarmEnum::ClayHouse || x == FarmEnum::WoodHouse || x == FarmEnum::StoneHouse) {
                houseRooms++;
            }
        }
    }
    return houseRooms;
}

void Player::addFamilyMember() {
    auto houseRooms = getHouseRooms();
    if (familyMembers < houseRooms && familyMembers < 5) {
        familyMembers++;
    }
}

void Player::addFamilyMemberNoPlace() {
    if (familyMembers < 5) {
        familyMembers++;
    }
}

unsigned int Player::getFamilyMembers() const {
    return familyMembers;
}

unsigned int Player::getFoodRequired() {
    return familyMembers * 2;
}

void Player::feedFamily() {
    while (warehouse->food.getResource() < getFoodRequired()) {
        warehouse->begCards.addResource();
        warehouse->food.addResource(2);
    }
    warehouse->food.decreaseResource(getFoodRequired());
}

bool Player::upgradeHouseClay() {
    if (farm[0][0] != FarmEnum::WoodHouse) {
        // cannot update to clay house. Already updated
        return false;
    } else if (getHouseRooms() * 2 > warehouse->clay.getResource() && warehouse->reed.getResource() < 1) {
        // cannot update to clay house. Required more materials
        return false;
    }
    warehouse->clay.decreaseResource(getHouseRooms() * 2);
    warehouse->reed.decreaseResource();

    for (auto &y: farm) {
        for (auto &x: y) {
            if (x == FarmEnum::WoodHouse) {
                x = FarmEnum::ClayHouse;
            }
        }
    }
    return true;
}

bool Player::upgradeHouseStone() {
    if (farm[0][0] != FarmEnum::ClayHouse) {
        // cannot update to clay house. Require update
        return false;
    } else if (getHouseRooms() * 2 > warehouse->stone.getResource() && warehouse->reed.getResource() < 1) {
        // cannot update to clay house. Required more materials
        return false;
    }
    warehouse->stone.decreaseResource(getHouseRooms() * 2);
    warehouse->reed.decreaseResource();

    for (auto &y: farm) {
        for (auto &x: y) {
            if (x == FarmEnum::ClayHouse) {
                x = FarmEnum::StoneHouse;
            }
        }
    }
    return true;
}

