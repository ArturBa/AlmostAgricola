//
// Created by artur on 23/02/2020.
//

#pragma once

#include <exception>
#include "Model.hh"
#include "ConcreteGameStrategy.hh"
#include "PlayerList.hh"
#include "PlayerIterator.hh"


/**
 * @class Game
 * @brief Main game class
 */
class Game {
private:
    std::vector<Player *> *players;
    GameStrategy *gameStrategy;
    Player *firstPlayer;
    PlayerIterator<Player *> *playerIterator;
    PlayerList<Player *> *playerList;
    int currentWeek = 0;
    bool weekHarvest[3] = {false, //false, false, true, false, false, true, false, false, true, false, false, true,
                           false, true};

    void playerTourList();

    void nextTour();

public:
    /**
     * @brief Default Game constructor
     * @param _players players taking part in the game
     */
    explicit Game(std::vector<Player *> *_players);

    /**
     * @brief Default Game deconstructor
     */
    ~Game();

    /**
     * @brief get current player
     * @return current player
     */
    Player *getCurrentPlayer();

    /**
     * @brief do certain action
     * @param action
     */
    void selectAction(Actions action);

    /**
     * Get map of available actions
     * @return map of available actions
     */
    [[nodiscard]] std::map<Actions, std::pair<bool, Player *>> getMapOfActions() const;

    /**
     * Get vector of players
     * @return vector of players
     */
    const std::vector<Player *> *getPlayers();

    /**
     * Count weeks until harvest
     * @return remaining weeks till harvest
     */
    [[nodiscard]] int weeksToHarvest() const;

};

/**
 * @class GameException
 * @brief Class for throwing exceptions in a game
 */
class GameException : public std::exception {
private:
    std::string errorMsg;
public:
    explicit GameException(std::string _errorMsg) : errorMsg(_errorMsg) {
        ;
    };

    [[nodiscard]] const char *what() const noexcept override {
        return errorMsg.c_str();
    }
};