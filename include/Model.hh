//
// Created by artur on 29/01/2020.
//

#pragma once

#include <SFML/Graphics.hpp>


class Model {
private:
    sf::Color bgColor;
    unsigned char *image;
    unsigned int width{}, height{};


public:
    Model();

    void setBgColor(const float color[3]);

    sf::Color getBgColor();

    bool loadImage(const std::string &fileName);

    unsigned char *getImage();

    unsigned int getWidth();

    unsigned int getHeight();
};
