//
// Created by artur on 21/02/2020.
//

#include "Farm.hh"

std::map<FarmEnum, Farm *> FarmFactory::mapOfFarm;

Farm *FarmFactory::getFarm(const FarmEnum farm) {
    auto searchFarm = mapOfFarm.find(farm);
    if (searchFarm != mapOfFarm.end()) {
        return searchFarm->second;
    } else {
        mapOfFarm.insert(std::pair<FarmEnum, Farm *>{farm, new Farm(farm)});
        return mapOfFarm.at(farm);
    }
}

Farm::Farm(FarmEnum farm) {
    farmImage.loadFromFile("../res/img/farm.png", getArea(farm));
}

sf::IntRect Farm::getArea(FarmEnum farm) {
    int i = 0;
    for (auto f: FarmEnum()) {
        if (f == farm)
            break;
        i++;
    }
    return sf::IntRect(i * FARM_SIZE, 0, FARM_SIZE, FARM_SIZE);
}

const sf::Texture &Farm::getTexture() const {
    return farmImage;
}