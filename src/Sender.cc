//
// Created by artur on 19/02/2020.
//

#include "Sender.hh"

void Sender::attach(Observer &observer) {
    observers.push_back(&observer);
}

void Sender::notify() {
    for (auto i : observers) {
        i->update();
    }
}

void Sender::detach(Observer &observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), &observer));
}

