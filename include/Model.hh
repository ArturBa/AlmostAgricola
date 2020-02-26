//
// Created by artur on 29/01/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Actions.hh"
#include "Player.hh"
#include "Game.hh"

class Game;


/**
 * @class Model
 * @brief Class connecting Frontend and Backend
 */
class Model {
private:
    std::map<Actions, bool> mapOfActions;
    Game *game;

public:
    /**
     * @brief Default constructor
     */
    Model();

    /**
     * @brief Start a new game
     * @param players players taking part in the game
     */
    void newGame(std::vector<Player> *players);

    /**
     * @brief Get current player
     * @return current player
     */
    Player * getCurrentPlayer();

    /**
     * @brief select action
     * @param action selected action
     */
    void selectAction(Actions action);

    /**
     * @brief get map of actions
     * @return map of actions
     */
    [[nodiscard]] const std::map<Actions, bool> *getMapOfActions() const;

};
