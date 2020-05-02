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
#include "Actions.hh"

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
    std::array<std::array<FarmEnum, FARM_WIDTH>, FARM_HEIGHT> farm{};
    unsigned int familyMembers;
    std::vector<UpgradeEnum> upgrades;

    unsigned int getHouseRooms();

    static bool isInFarm(unsigned int x, unsigned int y);

    bool isReplaceable(unsigned int x, unsigned int y);

    static bool isHouseType(FarmEnum farm);

    bool isNextToHouse(unsigned int x, unsigned int y);

    /**
     * @brief feed Family
     */
    void feedFamily();

public:
    Warehouse *warehouse;

    /**
     * @brief Default constructor for player
     * @param _name player name
     * @param playerTexture player texture pointer
     */
    Player(std::string _name, PlayerTexture *playerTexture);

    /**
     * @brief Default deconstructor
     */
    ~Player();

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
    bool setFarm(const unsigned int x, const unsigned int y, const FarmEnum fieldType);

    /**
     * @brief Transform one of player sheep into food
     * @details If player has a 1lvl kitchen it gives 3 food per sheep
     *          if 2 lvl kitchen it gives 4 food, else 2
     */
    bool transformSheepIntoFood(unsigned int sheepNo = 1);

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

    /**
     * @brief get food required for feeding family
     */
    unsigned int getFoodRequired();

    /**
     * @brief upgrade house to Clay house
     * @return status if success at upgrade
     */
    bool upgradeHouseClay();

    /**
     * @brief upgrade house to Stone house
     * @return status if success at upgrade
     */
    bool upgradeHouseStone();

    /**
     * @brief do all harvest actions on player
     */
    void harvest();

    void action(Actions action) const;
};

