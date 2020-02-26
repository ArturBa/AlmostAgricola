//
// Created by artur on 23/02/2020.
//

#include "Game.hh"

Game::Game(std::vector<Player> *_players) {
    players = _players;
}

Player * Game::getCurrentPlayer() {
    return &players->at(0);
}

Game::~Game() {
    delete players;
}
