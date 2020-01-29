//
// Created by artur on 29/01/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Save.hh"


class Model {
private:
    sf::Color bgColor;
    unsigned char *image;
    unsigned int width{}, height{};


public:
    Model();

    bool loadImage(const std::string &fileName);

    unsigned char *getImage();

    unsigned int getWidth();

    unsigned int getHeight();

    void setSettings() {};

    void preLoadSaves() {};

    void getSaves() {};

    void loadSave() {};
};
