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

bool Model::loadImage(const std::string &fileName) {
    sf::Image img;
    if (!img.loadFromFile(fileName)) {
        return false;
    }
    width = img.getSize().x;
    height = img.getSize().y;
    int size = 4 * width * height;
    image = new unsigned char[size];

    const unsigned char *pixptr;
    pixptr = img.getPixelsPtr();

    for (unsigned int i = 0; i < size; i++) {
        image[i] = *pixptr++;
    }
    return true;
}

unsigned char *Model::getImage() {
    return image;
}

Model::Model() :
        image(nullptr) {
    ;
}

unsigned int Model::getWidth() {
    return width;
}

unsigned int Model::getHeight() {
    return height;
}

