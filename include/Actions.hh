//
// Created by artur on 18/02/2020.
//

#pragma once

#include <string>

enum class Actions {
    GET_2_FOOD,
    GET_SHEEP,
    TEST,
    First = GET_2_FOOD,
    Last = GET_SHEEP
};

static Actions operator++(Actions &x) { return x = (Actions) (((int) (x) + 1)); }

static Actions operator*(Actions c) { return c; }

static Actions begin(Actions r) { return Actions::First; }

static Actions end(Actions r) { return Actions(int(Actions::Last) + 1); }


static std::string getActionFileName(Actions action) {
    switch (action) {
        case Actions::GET_2_FOOD:
            return "2_food";
        case Actions::GET_SHEEP:
            return "sheep";
        case Actions::TEST:
            return "test";
    }
}
