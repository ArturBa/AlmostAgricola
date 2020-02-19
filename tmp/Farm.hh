//
// Created by artur on 18/02/2020.
//

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <map>
#include <SFML/Graphics/Texture.hpp>

#define FARM_SIZE 128

class FarmFactory;

enum class FarmEnum {
    WoodHouse,
    ClayHouse,
    StoneHouse,
    Grass,
    Field,
    Pasture,
    First = WoodHouse,
    Last = Pasture
};

static FarmEnum operator++(FarmEnum &x) { return x = (FarmEnum) (((int) (x) + 1)); }

static FarmEnum operator*(FarmEnum c) { return c; }

static FarmEnum begin(FarmEnum r) { return FarmEnum::First; }

static FarmEnum end(FarmEnum r) { return FarmEnum(int(FarmEnum::Last) + 1); }

class Farm {
private:
    sf::Texture farmImage;

    sf::IntRect getArea(FarmEnum farm);

    Farm(FarmEnum farm);

    friend FarmFactory;
public:
    sf::Texture getImage();
};

class FarmFactory {
public:
    static Farm *getFarm(const FarmEnum farm);

private:
    static std::map<FarmEnum, Farm *> mapOfFarm;
};



