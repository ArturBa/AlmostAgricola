//
// Created by artur on 29/01/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Actions.hh"


class Model {
private:
    std::map<Actions, bool> mapOfActions;

    void resetActions();

public:
    Model();

    void newGame();

    void updateSettings();

    int getCurrentPlayer();

    void selectAction(Actions action);

    const std::map<Actions, bool> *getMapOfActions() const;

};
