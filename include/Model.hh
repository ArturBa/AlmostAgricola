//
// Created by artur on 29/01/2020.
//

#pragma once

#include <SFML/Graphics.hpp>


class Model {
private:
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

    void getWarehouse() {};

    void newGame() {};
};
