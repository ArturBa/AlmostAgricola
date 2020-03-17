//
// Created by artur on 29/01/2020.
//

#include <iostream>

#include "Model.hh"


Model::Model() {
    game = nullptr;
}

std::map<Actions, std::pair<bool, Player *>> Model::getMapOfActions() const {
    return game->getMapOfActions();
}

void Model::newGame(std::vector<Player *> *players) {
    game = new Game(players);
}

Player *Model::getCurrentPlayer() {
    return game->getCurrentPlayer();
}

void Model::selectAction(Actions action) {
    game->selectAction(action);
}
