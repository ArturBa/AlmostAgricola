//
// Created by artur on 02/03/2020.
//

#pragma once

#include "Player.hh"


class Points {
private:
    Player *player;

public:
    explicit Points(Player *_player);

    unsigned int getFamilyMembers();

    unsigned int getSheep();

    unsigned int getHouse();

};


