//
// Created by bauer on 2/11/20.
//

#pragma once

#include <string>
#include <SFML/Graphics.hpp>

/**
 * @class Player
 * @brief Basic player class
 */
class Player {
private:
    const int imageId;
    const std::string name;
    const sf::Color color;

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
    [[nodiscard]] std::string getName() const;
};

