//
// Created by artur on 18/02/2020.
//

#pragma once

#include <string>
#include <map>

enum class Actions {
    GET_2_FOOD,
    GET_SHEEP,
    GET_WOOD,
    WEEK_1_0,
    TEST,
    First = GET_2_FOOD,
    Last = WEEK_1_0
};

static Actions operator++(Actions &x) { return x = (Actions) (((int) (x) + 1)); }

static Actions operator*(Actions c) { return c; }

static Actions begin(Actions r) { return Actions::First; }

static Actions end(Actions r) { return Actions(int(Actions::Last) + 1); }


static const std::map<Actions, std::string> mapOfActionFileNames = {
        {Actions::GET_2_FOOD, "act_2_food"},
        {Actions::GET_SHEEP,  "act_sheep"},
        {Actions::GET_WOOD,   "act_wood"},
        {Actions::WEEK_1_0,   "act_week_1_0"},
};

/**
 * @brief Get action file name
 * @param action
 * @return file name
 */
static std::string getActionFileName(Actions action) {
    auto search = mapOfActionFileNames.find(action);
    if (search != mapOfActionFileNames.end()) {
        return search->second;
    } else {
        return "test";
    }
}
