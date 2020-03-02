//
// Created by artur on 02/03/2020.
//

#pragma once

#include <map>
#include "Actions.hh"
#include "Player.hh"


class GameStrategy {
public:
    virtual void nextAction() = 0;

    virtual void generateNextTourAction() = 0;

    virtual std::map<Actions, Player *> getMapOfActions() = 0;
};


