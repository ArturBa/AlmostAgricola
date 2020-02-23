//
// Created by artur on 23/02/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <map>

#define PLAYER_TEXTURE_ICON_SIZE 32
#define PLAYER_TEXTURE_ICON_NUMBER 3

class PlayerTexture;

class PlayerTextureFactory {
private:
    static std::map<int, PlayerTexture *> mapOfTextures;
public:
    static PlayerTexture *getPlayerTexture(unsigned int id);

};

class PlayerTexture {
private:
    explicit PlayerTexture(unsigned int id);

    sf::Texture texture;
    sf::Color color;
    static std::map<int, sf::Color> mapOfColors;

    static sf::Color getColor(unsigned int id);

    static sf::IntRect getIconRect(unsigned int id);

    friend class PlayerTextureFactory;

public:
    const sf::Texture &getTexture() const;

    const sf::Color &getColor() const;

public:
};


