//
// Created by artur on 18/02/2020.
//

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include "JsonLang.hh"

#define FARM_SIZE 128

class FarmFactory;

enum class FarmEnum {
    Grass,
    WoodHouse,
    ClayHouse,
    StoneHouse,
    Field,
    Pasture,
    First = WoodHouse,
    Last = Pasture
};

static FarmEnum operator++(FarmEnum &x) { return x = (FarmEnum) (((int) (x) + 1)); }

static FarmEnum operator*(FarmEnum c) { return c; }

static FarmEnum begin(FarmEnum r) { return FarmEnum::First; }

static FarmEnum end(FarmEnum r) { return FarmEnum(int(FarmEnum::Last) + 1); }

/**
 * @class Farm
 * @brief Class containing farm images
 */
class Farm {
private:
    sf::Texture farmImage;

    static sf::IntRect getArea(FarmEnum farm);

    explicit Farm(FarmEnum farm);

    friend FarmFactory;
public:
    /**
     * @brief Get Texture
     * @return Texture of farm
     */
    const sf::Texture &getTexture() const;
};

/**
 * @class FarmFactory
 * @brief Class creating Farms
 */
class FarmFactory {
public:
    /**
     * @brief Get Farm
     * @param farm farm type enum
     * @return Farm pointer
     */
    static Farm *getFarm(FarmEnum farm);

private:
    static std::map<FarmEnum, Farm *> mapOfFarm;
};



