//
// Created by artur on 29/01/2020.
//

#include <utility>

#include "Model.hh"


Model::Model() {
    for (auto action : Actions()) {
        mapOfActions.insert({action, {true}});
    }
    game = nullptr;
}

const std::map<Actions, bool> *Model::getMapOfActions() const {
    return &mapOfActions;
}

void Model::newGame(std::vector<Player> *players) {
    game = new Game(players);
}

Player *Model::getCurrentPlayer() {
    return game->getCurrentPlayer();
}

void Model::selectAction(Actions action) {

}
