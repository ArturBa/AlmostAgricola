//
// Created by bauer on 2/11/20.
//

#pragma once

#include <string>
#include <array>
#include <SFML/Graphics.hpp>
#include "Farm.hh"
#include "Upgrade.hh"
#include "PlayerTexture.hh"
#include "Warehouse.hh"

#define FARM_WIDTH 6
#define FARM_HEIGHT 4

/**
 * @class Player
 * @brief Basic player class
 */
class Player : public Warehouse {
private:
    const PlayerTexture *texture;
    const std::string name;
    std::array<std::array<FarmEnum, FARM_WIDTH>, FARM_HEIGHT> farm{};
    unsigned int familyMembers;
    std::vector<UpgradeEnum> upgrades;

    unsigned int getHouseRooms();

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
    [[nodiscard]] const PlayerTexture *getPlayerTexture() const;

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

    /**
     * @brief set farm field
     * @param x x location
     * @param y y location
     * @param fieldType field type to set
     */
    void setFarm(const unsigned int x, const unsigned int y, const FarmEnum fieldType);

    /**
     * @brief Get player number of sheep
     * @return number of player's sheep
     */
    [[nodiscard]] unsigned int getSheep() const;

    /**
     * @brief Add sheep to player's sheep
     * @param sheepNo number of sheep to add
     */
    void addSheep(unsigned int sheepNo = 1);

    /**
     * @brief Get player number of food
     * @return number of player's food units
     */
    [[nodiscard]] unsigned int getFood() const;

    /**
     * @brief Transform one of player sheep into food
     * @details If player has a 1lvl kitchen it gives 3 food per sheep
     *          if 2 lvl kitchen it gives 4 food, else 2
     */
    void transformSheepIntoFood(unsigned int sheepNo = 1);

    /**
     * @brief Add upgrade
     * @param upgrade upgrade to add to player
     */
    void addUpgrade(UpgradeEnum upgrade);

    /**
     * @brief Get Player's family member counter
     * @return player's family member number
     */
    [[nodiscard]] unsigned int getFamilyMembers() const;

    /**
     * @brief add family member with place check
     */
    void addFamilyMember();

    /**
     * @brief add family member without place check
     */
    void addFamilyMemberNoPlace();
};

