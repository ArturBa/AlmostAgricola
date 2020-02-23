//
// Created by artur on 23/02/2020.
//

#pragma once

#include "Model.hh"


class Game {
private:
    std::vector<Player> players;

    explicit Game(std::vector<Player> players);

    friend class Model;

};


