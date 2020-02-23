//
// Created by artur on 30/01/2020.
//

#pragma once

class ViewController;

/**
 * @class ViewAbstract
 * @brief Abstract class for creating interface for next state classes
 */
class ViewAbstract {
public:
    /**
     * @brief Constructor
     * @param _viewController [ViewController*]
     */
    explicit ViewAbstract(ViewController *_viewController);

    /**
     * @brief default GUI show method
     */
    virtual void display() = 0;

protected:
    ViewController *viewController;
};


