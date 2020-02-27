//
// Created by artur on 23/02/2020.
//

#pragma once

#include "Model.hh"


/**
 * @class Game
 * @brief Main game class
 */
class Game {
private:
    std::vector<Player> *players;

public:
    /**
     * @brief Default Game constructor
     * @param _players players taking part in the game
     */
    explicit Game(std::vector<Player> *_players);

    /**
     * @brief Default Game deconstructor
     */
    ~Game();

    /**
     * @brief get current player
     * @return current player
     */
    Player * getCurrentPlayer();
};


