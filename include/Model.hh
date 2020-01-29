//
// Created by artur on 29/01/2020.
//

#pragma once

#include <SFML/Graphics.hpp>


class Model {
private:
    sf::Color bgColor;


public:
    void setBgColor(const float color[3]);

    sf::Color getBgColor();

};
