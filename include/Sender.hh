//
// Created by artur on 19/02/2020.
//

#pragma once

#include <vector>
#include <algorithm>
#include "Observer.hh"

class Observer;

class Sender {
public:
    void attach(Observer &observer);

    void detach(Observer &observer);

    void notify();

private:
    std::vector<Observer *> observers;
};


