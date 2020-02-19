//
// Created by artur on 30/01/2020.
//

#pragma once

#include "Settings.hh"
#include "Window.hh"

/**
 * @class Application
 * @brief main application
 */
class Application {
private:
    Settings settings;
    Window window;

public:
    /**
     * @brief Default application constructor
     */
    Application();

    /**
     * @brief Application start
     */
    void start();
};


