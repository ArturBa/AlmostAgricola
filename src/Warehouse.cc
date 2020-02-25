//
// Created by artur on 25/02/2020.
//

#include <Warehouse.hh>

#include "Warehouse.hh"

Warehouse::Warehouse() {
    food = 2;
    sheep = 0;
}

unsigned int Warehouse::getSheep() const {
    return sheep;
}

unsigned int Warehouse::getFood() const {
    return food;
}
