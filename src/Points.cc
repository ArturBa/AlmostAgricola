//
// Created by artur on 02/03/2020.
//

#include "Points.hh"

Points::Points(Player *_player) {
    player = _player;
}

unsigned int Points::getHouse() {
    unsigned int points = 0;
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
