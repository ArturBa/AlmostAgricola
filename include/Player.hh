//
// Created by bauer on 2/11/20.
//

#pragma once

#include <string>

/**
 * @class Player
 * @brief Basic player class
 */
class Player {
private:
    const int imageId;
    const std::string name;

public:
    /**
     * Default constructor for player
     * @param _name player name
     * @param imageId image id
     */
    Player(std::string _name, int imageId);

    /**
     * Get image id
     * @return image id
     */
    [[nodiscard]] int getImageId() const;

    /**
     * Get player name
     * @return player name
     */
    std::string getName();

};

