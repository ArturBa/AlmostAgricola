//
// Created by artur on 25/02/2020.
//

#pragma once


class Warehouse {
protected:
    unsigned int sheep;
    unsigned int food;
public:
    Warehouse();

    [[nodiscard]] unsigned int getSheep() const;

    [[nodiscard]] unsigned int getFood() const;
};


