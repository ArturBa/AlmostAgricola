//
// Created by artur on 02/03/2020.
//

#include "ConcreteGameStrategy.hh"

ConcreteGameStrategy::ConcreteGameStrategy() {
    for (auto action: Actions()) {
        mapOfActions.insert(
                std::pair<Actions, std::pair<bool, Player *>>(action, std::pair<bool, Player *>(false, nullptr)));
    }
    mapOfActions.at(Actions::GET_2_FOOD).first = true;
    mapOfActions.at(Actions::GET_SHEEP).first = true;
}

std::map<Actions, std::pair<bool, Player *> > ConcreteGameStrategy::getMapOfActions() {
    return mapOfActions;
}

void ConcreteGameStrategy::selectAction(Actions action, Player *player) {
    mapOfActions.at(action).second = player;
}

void ConcreteGameStrategy::generateNextTourAction() {
    for (auto action: Actions()) {
        mapOfActions.at(action).second = nullptr;
    }
    mapOfActions.at(Actions::WEEK_1_0).first = true;
}

