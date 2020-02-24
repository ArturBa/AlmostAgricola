//
// Created by artur on 22/02/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

#include "JsonLang.hh"

#define UPGRADE_BUTTON_WIDTH 64
#define UPGRADE_BUTTON_HEIGHT 128

class UpgradeFactory;

enum class UpgradeEnum {
    Kitchen_0,
    Kitchen_1,
    Kitchen_2,
    Kitchen_3,
    TEST,
    First = Kitchen_0,
    Last = Kitchen_3
};

static UpgradeEnum operator++(UpgradeEnum &x) { return x = (UpgradeEnum) (((int) (x) + 1)); }

static UpgradeEnum operator*(UpgradeEnum c) { return c; }

static UpgradeEnum begin(UpgradeEnum r) { return UpgradeEnum::First; }

static UpgradeEnum end(UpgradeEnum r) { return UpgradeEnum(int(UpgradeEnum::Last) + 1); }

/**
 * @class Upgrade
 * @brief Class containing upgrades Textures and texts
 */
class Upgrade {
public:
    /**
     * Get texture of a upgrade
     * @return upgrade texture
     */
    const sf::Texture &getTexture() const;

    /**
     * Get upgrade text description
     * @return Text description
     */
    const std::string &getText() const;

private:
    sf::Texture texture;
    std::string text;

    explicit Upgrade(UpgradeEnum upgrade, JsonLang &langJson);

    friend UpgradeFactory;

    std::string getJsonText(JsonLang &langJson, const UpgradeEnum &upgrade);

    std::string getUpgradeFileName(const UpgradeEnum &upgrade);

    static std::map <UpgradeEnum, std::string> mapOfUpgradeFileNames;
};


/**
 * @class UpgradeFactory
 * @brief Class for creating and managing Upgrade classes
 */
class UpgradeFactory {
public:
    /**
     * Get Upgrade
     * @param upgrade UpgradeEnum for which get Upgrade
     * @param langJson json with all text
     * @return Upgrade pointer
     */
    static Upgrade *getUpgrade(UpgradeEnum upgrade, JsonLang &langJson);

private:
    static std::map<UpgradeEnum, Upgrade *> mapOfUpgrades;

};

