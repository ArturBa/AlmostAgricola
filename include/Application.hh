//
// Created by artur on 30/01/2020.
//

#pragma once

#include "ViewController.hh"
#include "Shared.hh"
#include <SFML/Graphics.hpp>
#include "imgui-SFML.h"
#include "imgui.h"
#include <imgui_internal.h>

/**
 * @class Application
 * @brief main application
 */
class Application {
private:
    Shared shared;
    ViewController viewController;
    sf::RenderWindow window;

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


