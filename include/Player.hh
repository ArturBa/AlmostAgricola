//
// Created by bauer on 2/11/20.
//

#pragma once

#include <string>

class Player {
private:
    const int imageId;
    const std::string name;

public:
    Player(std::string _name, int imageId);

    [[nodiscard]] int getImageId() const;

    std::string getName();

};

