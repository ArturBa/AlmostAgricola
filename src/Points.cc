//
// Created by artur on 02/03/2020.
//

#include "Points.hh"

Points::Points(Player *_player) {
    player = _player;
}

int Points::totalPoints() {
    return getHouse() + getSheep() + getFamilyMembers();
}

int Points::getHouse() {
    int points = 0;
    for (const auto &y : player->getFarm()) {
        for (const auto &x: y) {
            if (x == FarmEnum::ClayHouse) {
                points++;
            } else if (x == FarmEnum::StoneHouse) {
                points += 2;
            }
        }
    }
    return points;
}

int Points::getSheep() {
    int points = -1;
    if (player->warehouse->sheep.getResource() >= 1) {
        points++, points++;
    }
    if (player->warehouse->sheep.getResource() >= 4) {
        points++;
    }
    if (player->warehouse->sheep.getResource() >= 6) {
        points++;
    }
    if (player->warehouse->sheep.getResource() >= 8) {
        points++;
    }
    return points;
}

int Points::getFamilyMembers() {
    return 3 * player->getFamilyMembers();
}
