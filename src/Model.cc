//
// Created by artur on 29/01/2020.
//

#include "Model.hh"

void Model::setBgColor(const float *color) {
    bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
    bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
    bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
}

sf::Color Model::getBgColor() {
    return bgColor;
}
