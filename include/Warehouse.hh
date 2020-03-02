//
// Created by artur on 25/02/2020.
//

#pragma once

#include "Resource.hh"


/**
 * @class Warehouse
 * @brief Class for warehouse status
 */
class Warehouse {
public:
    Resource food{};
    Resource wheat{};
    Resource vegetable{};
    Resource clay{};
    Resource wood{};
    Resource stone{};
    Resource reed{};
    Resource sheep{};
    Resource swine{};
    Resource cow{};
    Resource begCards{};

    /**
     * @brief Default constructor
     */
    Warehouse();
};


