//
// Created by artur on 23/02/2020.
//

#include "PlayerTexture.hh"

std::map<int, PlayerTexture *> PlayerTextureFactory::mapOfTextures;

PlayerTexture *PlayerTextureFactory::getPlayerTexture(const unsigned int id) {
    auto searchPlayerTexture = mapOfTextures.find(id);
    if (searchPlayerTexture != mapOfTextures.end()) {
        return searchPlayerTexture->second;
    } else {
        mapOfTextures.insert(std::pair<int, PlayerTexture *>{id, new PlayerTexture(id)});
        return mapOfTextures.at(id);
    }
}

std::map<int, sf::Color> PlayerTexture::mapOfColors = {
        {0, {0xd5, 0x00, 0xd5}},
        {1, {0xe2, 0xc0, 0x95}},
        {2, {0x00, 0xff, 0x00}},
        {3, {0x00, 0x00, 0xff}}
};

sf::IntRect PlayerTexture::getIconRect(const unsigned int id) {
    if (id > PLAYER_TEXTURE_ICON_NUMBER) {
        return {0, 0, PLAYER_TEXTURE_ICON_SIZE, PLAYER_TEXTURE_ICON_SIZE};
    };
    return {id * PLAYER_TEXTURE_ICON_SIZE, 0, PLAYER_TEXTURE_ICON_SIZE, PLAYER_TEXTURE_ICON_SIZE};
}

sf::Color PlayerTexture::getColor(const unsigned int id) {
    try {
        return mapOfColors.at(id);
    } catch (std::exception &e) {
        return {100, 100, 100};
    }
}

PlayerTexture::PlayerTexture(const unsigned int id) {
    texture.loadFromFile("../res/img/players_icon.png", getIconRect(id));
    color = getColor(id);
}

const sf::Texture &PlayerTexture::getTexture() const {
    return texture;
}

const sf::Color &PlayerTexture::getColor() const {
    return color;
}
