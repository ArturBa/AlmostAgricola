//
// Created by artur on 19/02/2020.
//

#pragma once

#include <vector>
#include <algorithm>
#include "Observer.hh"

class Observer;

/**
 * @class Sender
 * @brief Class complementary to Observer
 */
class Sender {
public:
    /**
     * @brief Attach new Observer
     * @param observer observer to attach
     */
    void attach(Observer &observer);

    /**
     * @brief Detach Observer
     * @param observer Observer to detach
     */
    void detach(Observer &observer);

    /**
     * @brief Notify all observers
     */
    void notify();

private:
    std::vector<Observer *> observers;
};


