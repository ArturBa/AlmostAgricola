//
// Created by artur on 02/03/2020.
//

#pragma once

#include "GameStrategy.hh"

class ConcreteGameStrategy : public GameStrategy {
private:
    std::map<Actions, std::pair<bool, Player *>> mapOfActions;
public:
    ConcreteGameStrategy();

    std::map<Actions, std::pair<bool, Player *> > getMapOfActions() override;

    void selectAction(Actions action, Player *player) override;

    void generateNextTourAction() override;
};


