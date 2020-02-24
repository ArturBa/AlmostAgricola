//
// Created by artur on 19/02/2020.
//

#pragma once

#include "Sender.hh"

class Sender;

/**
 * @class Observer
 * @brief interface for observer
 */
class Observer {
private:
    Sender *sender;
public:
    /**
     * Update class caused by sender change
     */
    virtual void update() = 0;

    /**
     * @brief Default constructor
     * @param _sender Sender class pointer
     */
    explicit Observer(Sender *_sender);

    /**
     * @brief Class destructor
     */
    ~Observer();
};


