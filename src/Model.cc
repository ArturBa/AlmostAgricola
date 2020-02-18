//
// Created by artur on 29/01/2020.
//

#include "Model.hh"


Model::Model() {
    for (auto action : Actions()) {
        mapOfActions.insert({action, {true}});
    }
}

void Model::resetActions() {
    for (auto i : mapOfActions) {
        i.second = true;
    }
}

const std::map<Actions, bool> *Model::getMapOfActions() const {
    return &mapOfActions;
}
