//
// Created by artur on 27/02/2020.
//

#include "Resource.hh"

unsigned int Resource::getResource() const {
    return value;
}

void Resource::addResource(unsigned int resourceNo) {
    value += resourceNo;
}

bool Resource::decreaseResource(unsigned int resourceNo) {
    if (resourceNo > value)
        return false;
    value -= resourceNo;
    return true;
}
