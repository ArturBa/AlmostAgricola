//
// Created by artur on 30/01/2020.
//

#pragma once

#include "ViewAbstract.hh"
#include "Shared.hh"

/**
 * @enum Display modes
 * @brief Main view modes
 */
enum class ViewEnum {
    menu,   /**< Menu mode */
    game    /**< Game mode */
};

/**
 * @class ViewController
 * @brief Class for view control
 */
class ViewController {
public:
    /**
     * @brief Constructor
     * @param _shared common shared data
     */
    explicit ViewController(Shared *_shared);

    /**
     * @brief Display method used for showing GUI
     */
    void display();

    /**
     * @brief Get Shared data pointer
     * @return Shared data pointer
     */
    [[nodiscard]] Shared *getShared() const;

    /**
     * @brief Change display mode to selected
     * @param view selected view
     */
    void switchTo(ViewEnum view);

private:
    Shared *shared;
    ViewAbstract *currentView;
};


