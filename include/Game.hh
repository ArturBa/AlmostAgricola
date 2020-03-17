//
// Created by artur on 23/02/2020.
//

#pragma once

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

    void playerTourList();

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
};


