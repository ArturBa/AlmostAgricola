//
// Created by artur on 23/02/2020.
//

#include <utility>
#include "Game.hh"

Game::Game(std::vector<Player> _players) : players(std::move(_players)) {
    ;
}

Player *Game::getCurrentPlayer() {
    return &players[0];
}
