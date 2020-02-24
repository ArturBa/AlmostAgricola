//
// Created by bauer on 2/11/20.
//

#pragma once

#include <string>
#include <array>
#include <SFML/Graphics.hpp>
#include "Farm.hh"

#define FARM_WIDTH 6
#define FARM_HEIGHT 4

/**
 * @class Player
 * @brief Basic player class
 */
class Player {
private:
    const int imageId;
    const std::string name;
    const sf::Color color;
    std::array<std::array<FarmEnum, FARM_WIDTH>, FARM_HEIGHT> farm = {FarmEnum::Grass};

public:
    /**
     * @brief Default constructor for player
     * @param _name player name
     * @param imageId image id
     */
    Player(std::string _name, int imageId);

    /**
     * @brief Get image id
     * @return image id
     */
    [[nodiscard]] int getImageId() const;

    /**
     * @brief Get player name
     * @return player name
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Get farm
     * @return Farm array
     */
    [[nodiscard]] std::array<std::array<FarmEnum, FARM_WIDTH>, FARM_HEIGHT> getFarm();
};

