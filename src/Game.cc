//
// Created by artur on 23/02/2020.
//

#include "Game.hh"

Game::Game(std::vector<Player *> *_players) {
    players = _players;
    firstPlayer = players->at(0);
    gameStrategy = new ConcreteGameStrategy();
    playerList = nullptr;
    playerIterator = nullptr;
    playerTourList();
}

Player *Game::getCurrentPlayer() {
    return playerIterator->currentItem();
}

Game::~Game() {
    delete players;
}

std::map<Actions, std::pair<bool, Player *>> Game::getMapOfActions() const {
    return gameStrategy->getMapOfActions();
}

void Game::selectAction(Actions action) {
    gameStrategy->selectAction(action, getCurrentPlayer());
    playerIterator->next();
    if (playerIterator->isDone()) {
        for (auto player : *players) {
            player->feedFamily();
        }
        playerTourList();
    }
}

const std::vector<Player *> *Game::getPlayers() {
    return players;
}

void Game::playerTourList() {
    delete playerList;
    delete playerIterator;
    unsigned int playerFamilyMembers[players->size()];
    unsigned int tours = 0;
    for (int i = 0; i < players->size(); i++) {
        playerFamilyMembers[i] = players->at(i)->getFamilyMembers();
        tours += playerFamilyMembers[i];
    }

    int player = std::distance(players->begin(), std::find(players->begin(), players->end(), firstPlayer));

    playerList = new PlayerList<Player *>(tours);
    for (unsigned int i = 0; i < tours; i++) {
        playerList->add(players->at(player));
        player++;
        if (player >= players->size())
            player = 0;
    }
    playerIterator = playerList->createIterator();
}
