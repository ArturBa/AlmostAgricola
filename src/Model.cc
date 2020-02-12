//
// Created by artur on 29/01/2020.
//

#include "Model.hh"

bool Model::loadImage(const std::string &fileName) {
    sf::Image img;
    if (!img.loadFromFile(fileName)) {
        return false;
    }
    width = img.getSize().x;
    height = img.getSize().y;
    unsigned int size = 4 * width * height;
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

