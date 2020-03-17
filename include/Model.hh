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
    void newGame(std::vector<Player *> *players);

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
    [[nodiscard]] std::map<Actions, std::pair<bool, Player *>> getMapOfActions() const;

    /**
     * Get number of weeks until next harvest
     * @return number of weeks until next harvest
     */
    int weeksToHarvest();

    /**
     * Get vector of players
     * @return vector of players
     */
    const std::vector<Player *> *getPlayers();
};
