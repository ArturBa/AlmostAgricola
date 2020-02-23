//
// Created by artur on 29/01/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Actions.hh"
#include "Player.hh"
#include "Game.hh"

class Game;


class Model {
private:
    std::map<Actions, bool> mapOfActions;
    Game *game;

    void resetActions();

public:
    Model();

    void newGame(std::vector<Player> players);

    void updateSettings();

    int getCurrentPlayer();

    void selectAction(Actions action);

    [[nodiscard]] const std::map<Actions, bool> *getMapOfActions() const;

};
