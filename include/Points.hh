//
// Created by artur on 02/03/2020.
//

#pragma once

#include "Player.hh"

/**
 * @class Points
 * @brief Class for calculate points for each player
 */
class Points {
private:
    Player *player;

public:
    /**
     * @brief Constructor
     * @param _player player reference
     */
    explicit Points(Player *_player);

    /**
     * @brief get points from family members
     * @return points from family members
     */
    unsigned int getFamilyMembers();

    /**
     * @brief get points from sheep
     * @return points from sheep
     */
    unsigned int getSheep();

    /**
     * @brief get points from house level
     * @return points from house level
     */
    unsigned int getHouse();

};


