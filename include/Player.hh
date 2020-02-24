//
// Created by bauer on 2/11/20.
//

#pragma once

#include <string>
#include <array>
#include <SFML/Graphics.hpp>
#include "Farm.hh"
#include "PlayerTexture.hh"

#define FARM_WIDTH 6
#define FARM_HEIGHT 4

/**
 * @class Player
 * @brief Basic player class
 */
class Player {
private:
    const PlayerTexture *texture;
    const std::string name;
    const sf::Color color;
    std::array<std::array<FarmEnum, FARM_WIDTH>, FARM_HEIGHT> farm = {FarmEnum::Grass};

public:
    /**
     * @brief Default constructor for player
     * @param _name player name
     * @param playerTexture player texture pointer
     */
    Player(std::string _name, PlayerTexture *playerTexture);

    /**
     * @brief Get image id
     * @return image id
     */
    [[nodiscard]] const PlayerTexture *getTexture() const;

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

