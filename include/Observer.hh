//
// Created by artur on 19/02/2020.
//

#pragma once

#include "Sender.hh"

class Sender;

class Observer {
private:
    Sender *sender;
public:
    virtual void update() = 0;

    explicit Observer(Sender *_sender);

    ~Observer();
};


