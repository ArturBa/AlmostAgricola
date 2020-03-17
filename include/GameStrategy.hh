//
// Created by artur on 02/03/2020.
//

#pragma once

#include <map>
#include "Actions.hh"
#include "Player.hh"


class GameStrategy {
public:
    /**
     * @brief Generate next tour action
     */
    virtual void generateNextTourAction() = 0;

    /**
     * @brief Select action for a player
     * @param action selected action
     * @param player selected player
     */
    virtual void selectAction(Actions action, Player *player) = 0;

    /**
     * @brief Get a map of available actions
     * @return map of available actions
     */
    virtual std::map<Actions, std::pair<bool, Player *>> getMapOfActions() = 0;
};


